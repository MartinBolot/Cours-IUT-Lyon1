-- chose schema
use formation50;
-- drop table
drop table refine3_violations;
-- create table
create table refine3_violations
(
	PlateID string,
	RegistrationState string,
	IssueDate string,
	ViolationCode int,
	HouseNumber string,
	StreetName string
)
stored as orc;
insert into table refine3_violations
select
	PlateID, RegistrationState, IssueDate, ViolationCode, HouseNumber, StreetName
from refine2_violations
where IssueDate is not null;
-- count to check
select count(1) from refine3_violations;
