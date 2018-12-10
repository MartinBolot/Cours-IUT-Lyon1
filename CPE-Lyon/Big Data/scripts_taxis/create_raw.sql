-- chose schema
use formation50;
-- drop table
drop table if exists raw_taxi;
-- create raw table
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

-- count to check
select count(1) from raw_taxi;
