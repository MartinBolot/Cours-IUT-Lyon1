-- chose schema
use formation50;
-- drop table
drop table if exists refine4_taxi;
-- create table
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

-- count to check
select count(1) from refine4_taxi;

-- select sample to check
select
	tpep_pickup_datetime,
	tpep_dropoff_datetime,
	PULocationID,
	DOLocationID
from refine4_taxi
limit 10;
