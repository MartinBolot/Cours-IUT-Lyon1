-- create
create external table raw_taxi (
	VendorID int,
	tpep_pickup_datetime string,
	tpep_dropoff_datetime string,
	passenger_count int,
	trip_distance int,
	pickup_longitude decimal,
	pickup_latitude decimal,
	RatecodeID int,
	store_and_fwd_flag string,
	dropoff_longitude decimal,
	dropoff_latitude decimal,
	payment_type int,
	fare_amount int,
	extra int,
	mta_tax int,
	tip_amount int,
	tolls_amount int,
	improvement_surcharge int,
	total_amount int,
	PULocationID int,
	DOLocationID int
)
row format delimited fields terminated by ','
stored as textfile
location '/user/formation35/taxi/'
tblproperties ("skip.header.line.count"="1");

-- reduce the number of rows
create table refine1_taxi(
	VendorID int,
	tpep_pickup_datetime string,
	tpep_dropoff_datetime string,
	passenger_count int,
	trip_distance int,
	pickup_longitude decimal,
	pickup_latitude decimal,
	RatecodeID int,
	store_and_fwd_flag string,
	dropoff_longitude decimal,
	dropoff_latitude decimal,
	payment_type int,
	fare_amount int,
	extra int,
	mta_tax int,
	tip_amount int,
	tolls_amount int,
	improvement_surcharge int,
	total_amount int,
	PULocationID int,
	DOLocationID int
)
stored as orc;
insert into table refine1_taxi
select *
from raw_taxi limit 100000;

-- reduce the number of columns
create table refine2_taxi(
	tpep_pickup_datetime string,
	tpep_dropoff_datetime string,
	PULocationID int,
	DOLocationID int
)
stored as orc;
insert into table refine2_taxi
select tpep_pickup_datetime, tpep_dropoff_datetime, PULocationID, DOLocationID
from refine1_taxi;

-- clean (remove null pk)
create table refine3_taxi(
	tpep_pickup_datetime string,
	tpep_dropoff_datetime string,
	PULocationID int,
	DOLocationID int
)
stored as orc;
insert into table refine3_taxi
select *
from refine2_taxi
where tpep_dropoff_datetime is not null;

-- format
create table refine4_taxi(
	tpep_pickup_datetime date,
	tpep_dropoff_datetime date,
	PULocationID int,
	DOLocationID int
)
stored as orc;
insert into table refine4_taxi
select
	to_date(from_unixtime(UNIX_TIMESTAMP(SUBSTR(tpep_pickup_datetime,0,10), 'MM/dd/yyyy'))),
	to_date(from_unixtime(UNIX_TIMESTAMP(SUBSTR(tpep_dropoff_datetime,0,10), 'MM/dd/yyyy'))),
	PULocationID,
	DOLocationID
from refine3_taxi;

-- agregate
create table refine1_nbtaxi(
	taxi_ride_date date,
	nb_pu int,
	nb_do int
)
stored as orc;
insert into table refine1_nbtaxi
select
	tpep_pickup_datetime,
	count(tpep_pickup_datetime) as nb_pu,
	count(tpep_dropoff_datetime) as nb_do
from refine4_taxi
group by tpep_pickup_datetime;

/*
// normalize [select (value-MIN) / MAX-MIN)]

// <script>
//     max = select max(nb_pu) from refine1_nbtaxi | select max(nb_do) from refine1_nbtaxi
//     max' = max

//     min = select min(nb_pu) from refine1_nbtaxi | select min(nb_do) from refine1_nbtaxi
*/

create table refine2_nbtaxi(
	taxi_ride_date date,
	nb_pu_norm double,
	nb_do_norm double
)
stored as orc;
insert into table refine2_nbtaxi
select
	taxi_ride_date,
	(nb_pu-1)/(3-1) as nb_pu_norm,
	(nb_do-1)/(3-1) as nb_do_norm
from refine1_nbtaxi;

-- SELECT cast(date_format('2018-06-05 15:25:42.23','yyyy-MM-dd') as date);
