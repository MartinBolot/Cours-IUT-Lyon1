use formation50;
drop table if exists refine1_violations;
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
insert into table refine1_violations
select * from raw_violations limit 10000;
select count(1) from refine1_violations;
