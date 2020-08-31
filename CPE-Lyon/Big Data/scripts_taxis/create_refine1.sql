-- chose schema
use formation50;
-- drop table
drop table if exists refine1_taxi;
-- create table
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
from raw_taxi
/*limit 1000000*/;

-- count to check
select count(1) from refine1_taxi;
