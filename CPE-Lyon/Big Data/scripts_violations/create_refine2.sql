-- chose schema
use formation50;
-- drop table
drop table if exists refine2_violations;
-- create table
create table refine2_violations
(
	PlateID string,
	RegistrationState string,
	IssueDate string,
	ViolationCode int,
	HouseNumber string,
	StreetName string
)
stored as orc;

-- insert data with limited columns
insert into table refine2_violations
select
	PlateID, RegistrationState, IssueDate, ViolationCode, HouseNumber, StreetName
from refine1_violations;

-- count to check
select count(1) from refine2_violations;

-- select small sample to check
select
	PlateID, RegistrationState, IssueDate, ViolationCode, HouseNumber, StreetName
from refine2_violations limit 10;
