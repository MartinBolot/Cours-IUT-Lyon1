-- create raw table
create external table raw_violations
(
	SummonsNumber int,
	PlateID string,
	RegistrationState string,
	PlateType string,
	IssueDate string,
	ViolationCode int,
	VehicleBodyType string,
	VehicleMake string,
	IssuingAgency string,
	StreetCode1 int,
	StreetCode2 int,
	StreetCode3 int,
	VehicleExpirationDate int,
	ViolationLocation string,
	ViolationPrecinct int,
	IssuerPrecinct int,
	IssuerCode int,
	IssuerCommand string,
	IssuerSquad string,
	ViolationTime string,
	TimeFirstObserved string,
	ViolationCounty string,
	ViolationInFrontOfOrOpposite string,
	HouseNumber string,
	StreetName string,
	IntersectingStreet string,
	DateFirstObserved int,
	LawSection int,
	SubDivision string,
	ViolationLegalCode string,
	DaysParkingInEffect string,
	FromHoursInEffect string,
	ToHoursInEffect string,
	VehicleColor string,
	UnregisteredVehicle string,
	VehicleYear int,
	MeterNumber string,
	FeetFromCurb int,
	ViolationPostCode string,
	ViolationDescription string,
	NoStandingorStoppingViolation string,
	HydrantViolation string,
	DoubleParkingViolation string
)
row format delimited fields terminated by ','
stored as textfile
location '/user/formation50/violations/raw_violations'
tblproperties ("skip.header.line.count"="1");

-- take a sample
create table refine1_violations
(
	SummonsNumber int,
	PlateID string,
	RegistrationState string,
	PlateType string,
	IssueDate string,
	ViolationCode int,
	VehicleBodyType string,
	VehicleMake string,
	IssuingAgency string,
	StreetCode1 int,
	StreetCode2 int,
	StreetCode3 int,
	VehicleExpirationDate int,
	ViolationLocation string,
	ViolationPrecinct int,
	IssuerPrecinct int,
	IssuerCode int,
	IssuerCommand string,
	IssuerSquad string,
	ViolationTime string,
	TimeFirstObserved string,
	ViolationCounty string,
	ViolationInFrontOfOrOpposite string,
	HouseNumber string,
	StreetName string,
	IntersectingStreet string,
	DateFirstObserved int,
	LawSection int,
	SubDivision string,
	ViolationLegalCode string,
	DaysParkingInEffect string,
	FromHoursInEffect string,
	ToHoursInEffect string,
	VehicleColor string,
	UnregisteredVehicle string,
	VehicleYear int,
	MeterNumber string,
	FeetFromCurb int,
	ViolationPostCode string,
	ViolationDescription string,
	NoStandingorStoppingViolation string,
	HydrantViolation string,
	DoubleParkingViolation string
)
stored as orc;
insert into table refine1_violations select * from raw_violations limit 10000;

-- filter out columns
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
insert into table refine2_violations
select
	PlateID, RegistrationState, IssueDate, ViolationCode, HouseNumber, StreetName
from refine1_violations;

-- filter out null pk
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

-- convert string to date
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

-- create aggregates
create table refine1_nbviolations
(
	IssueDate date,
	NbViolations int
)
stored as orc;
insert into table refine1_nbviolations
select IssueDate, count(IssueDate) as NbViolations
from refine4_violations
group by IssueDate;

-- create normalized aggregates
-- select max(NbViolations) from refine1_nbviolations;
-- select min(NbViolations) from refine1_nbviolations;
create table refine2_nbviolations
(
	IssueDate date,
	NbViolations double
)
stored as orc;
insert into table refine2_nbviolations
select IssueDate, ((NbViolations-1)/(1015-1))
from refine1_nbviolations;
