-- chose schema
use formation50;
-- drop table
drop table if exists refine4_violations;
-- create table
create table refine4_violations
(
	PlateID string,
	RegistrationState string,
	IssueDate date,
	ViolationCode int,
	HouseNumber string,
	StreetName string
)
stored as orc;
insert into table refine4_violations
select
	PlateID,
	RegistrationState,
	to_date(from_unixtime(UNIX_TIMESTAMP(issuedate, 'MM/dd/yyyy'))),
	ViolationCode,
	HouseNumber,
	StreetName
from refine3_violations;

-- count to check
select count(1) from refine4_violations;

-- select sample to check
select
	PlateID,
	RegistrationState,
	IssueDate,
	ViolationCode,
	HouseNumber,
	StreetName
from refine4_violations
limit 10;
