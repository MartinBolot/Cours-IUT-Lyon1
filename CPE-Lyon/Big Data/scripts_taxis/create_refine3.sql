-- chose schema
use formation50;
-- drop table
drop table if exists refine3_taxi;
-- create table
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

-- count to check
select count(1) from refine3_taxi;
