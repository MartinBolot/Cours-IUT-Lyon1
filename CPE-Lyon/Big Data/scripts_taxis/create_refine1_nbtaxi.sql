-- chose schema
use formation50;
-- drop table
drop table if exists refine1_nbtaxi;
-- create table
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

-- count to check
select count(1) from refine1_nbtaxi;

-- check that there is only unique data
select count(1), taxi_ride_date from refine1_nbtaxi group by taxi_ride_date having count(1) > 1;
