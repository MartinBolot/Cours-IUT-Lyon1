-- chose schema
use formation50;
-- drop table
drop table if exists raw_violations;
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

-- count to check
select count(1) from raw_violations;
