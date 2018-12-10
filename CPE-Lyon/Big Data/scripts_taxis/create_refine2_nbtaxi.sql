-- chose schema
use formation50;
-- drop table
drop table if exists refine2_nbtaxi;
-- create table
create table refine2_nbtaxi(
	taxi_ride_date date,
	nb_pu_norm double,
	nb_do_norm double
)
stored as orc;
insert into table refine2_nbtaxi
select
	taxi_ride_date,
	(nb_pu-78133)/(456980-78133) as nb_pu_norm,
	(nb_do-78133)/(456980-78133) as nb_do_norm
from refine1_nbtaxi;

-- count to check
select count(1), taxi_ride_date from refine2_nbtaxi group by taxi_ride_date having count(1) > 1;

-- select sample
select taxi_ride_date, nb_pu_norm, nb_do_norm from refine2_nbtaxi limit 10;
