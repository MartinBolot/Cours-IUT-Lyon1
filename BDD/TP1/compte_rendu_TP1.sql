Compte rendu TP1 BDD :

1)
update emp set sal=0 where(
  lower(job)='salesman'
);

2)
select * from emp where lower(job)='salesman';

3)
ROLLBACK ();

4)
update emp 
  set sal=sal+0.05*(
    select sal from emp where lower(ename)='king'
) where(
  lower(job)='manager'
);

5)
select * from emp where lower(job)='manager';

6)
rollback;

7)
insert into salgrade(
    select deptno,min(sal),max(sal) from emp group by deptno
);
  8)
select * from salgrade;

9)
rollback;

10)
delete from emp where ename in (
  select ename from emp emp1 where(
    emp1.sal < (
      select avg(sal) from emp group by deptno having( deptno=emp1.deptno)
    )
  )
);

11)
create view toto as select * from emp where lower(job)='manager';

12)
update toto set sal=sal*1.1;

13)
select * from emp where lower(job)='manager';

14)
rollback;
select * from emp where lower(job)='manager';

15)
drop view toto;
