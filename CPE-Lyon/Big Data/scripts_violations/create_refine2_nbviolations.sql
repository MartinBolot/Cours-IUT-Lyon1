-- chose schema
use formation50;
-- drop table
drop table if exists refine2_nbviolations;
-- create table
create table refine2_nbviolations
(
	IssueDate date,
	NbViolations double
)
stored as orc;
insert into table refine2_nbviolations
select
	IssueDate,
	((NbViolations-1)/(1015-1))
from refine1_nbviolations;

-- count to check
select count(1), IssueDate from refine2_nbviolations group by IssueDate having count(1) > 1;

-- select sample
select IssueDate, NbViolations from refine2_nbviolations limit 10;
