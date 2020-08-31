-- chose schema
use formation50;
-- drop table
drop table if exists results_nbviolationstaxi;
-- create table
create table results_nbviolationstaxi
(
	IssueDate date,
	NbViolations double,
	NbPuNorm double
)
stored as orc;
insert into results_nbviolationstaxi
-- select
-- all data matching left and left+right
select
	vi.issuedate,
	vi.nbviolations,
	ta.nb_pu_norm
from refine2_nbviolations vi
	left join refine2_nbtaxi ta
	on vi.issuedate = ta.taxi_ride_date
-- all data matching only right
union
select
	ta.taxi_ride_date,
	vi.nbviolations,
	ta.nb_pu_norm
from refine2_nbviolations vi
	right join refine2_nbtaxi ta
	on vi.issuedate = ta.taxi_ride_date
where vi.issuedate is null;

-- count to check
select count(1) from results_nbviolationstaxi;
