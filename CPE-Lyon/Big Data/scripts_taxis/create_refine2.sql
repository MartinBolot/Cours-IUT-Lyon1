-- chose schema
use formation50;
-- drop table
drop table if exists refine2_taxi;
-- create table
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

-- count to check
select count(1) from refine2_taxi;

-- select small sample to check
select
	PlateID, RegistrationState, IssueDate, ViolationCode, HouseNumber, StreetName
from refine2_taxi limit 10;
