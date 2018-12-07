-- chose schema
use formation50;
-- select
select
	issuedate,
	nbviolations,
	nb_pu_norm
from refine2_nbviolations
union
select
	issuedate,
	nbviolations,
	nb_pu_norm
from refine2_nbviolations
