-- chose schema
use formation50;
-- drop table
drop table if exists refine1_nbviolations;
-- create table
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

-- count to check
select count(1) from refine1_nbviolations;

-- check that there is only unique data
select count(1), IssueDate from refine1_nbviolations group by IssueDate having count(1) > 1;
