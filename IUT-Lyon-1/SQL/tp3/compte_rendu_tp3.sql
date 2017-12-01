Compte rendu tp3

1)
select ename from emp where deptno in (
  select distinct dept.deptno from dept,emp where (
    dept.deptno=emp.deptno
    and lower(emp.job)='clerk'
  )
);

2)
select * from emp where(
  job in(
    select distinct job from emp,dept where(
      emp.deptno=dept.deptno
      and lower(dept.dname)='sales'
    )
  )
  and deptno=10
);

3)
select ename,comm,sal,(decode(comm,null,0,comm)/sal) as "ratio" from emp where(
  lower(job)='salesman'
  and sal!=0
) order by (decode(comm,null,0,comm)/sal) asc;

4)
select deptno,job,avg(sal) as "moyenne salaire" from emp group by deptno,job;



5)
select job,avg(sal) as "moyenne salaire" from emp group by job having(count(*)>=2);

6)

Select dname from dept where deptno in(
	Select deptno from emp group by deptno having count(*)=(
	Select max(count(*)) from emp group by deptno
)
)


7)
select emp.deptno from emp,salgrade where(
  emp.sal > salgrade.losal
  and emp.sal <= salgrade.hisal
) group by emp.deptno having(
    count(distinct salgrade.grade) in (
      select count(grade) from salgrade
    )
) order by deptno asc;

8)
select emp1.deptno from emp emp1,salgrade where(
  emp1.sal > salgrade.losal
  and emp1.sal <= salgrade.hisal
  and salgrade.grade=1
) group by emp1.deptno having(count(*) in (
    select count(*) from emp,dept where(
      emp.deptno=dept.deptno
      and emp.deptno=emp1.deptno
    ) group by emp.deptno
)
);

9)
select distinct sal from emp where(
  sal = (
    select max(sal) from emp where(
      lower(job)!='president'
    )
  )
  or sal = (
    select min(sal) from emp
  )
);

10)
select distinct emp2.deptno,emp1.job from emp emp1,emp emp2 
minus
select distinct emp.deptno,job from emp,dept where(
  emp.deptno=dept.deptno
) order by deptno asc;

11)

select deptno from dept
minus
select distinct dept.deptno from emp,dept where (
  emp.deptno=dept.deptno
  and lower(emp.job)='manager'
);

12)

select deptno from emp group by deptno having (
  count(distinct job) in (
    select count(distinct job) from emp
  )
);





13)
select deptno,job,avg(sal) from emp where(
  sal>1000
) group by deptno,job
order by deptno asc;

14)
select emp1.ename,count(emp1.empno) from emp emp1,emp emp2 where(
  emp1.empno=emp2.mgr
) group by emp1.ename;

15)
select emp1.ename,emp2.ename from emp emp1,emp emp2 where(
  emp1.empno=emp2.mgr
)
order by emp1.ename asc;

16)
select ename,sal from emp where(
  sal in (
    select max(sal) from emp
  )
);

17)
select distinct NU from U where(
  U.NU in (select NU from PUF)
  and not exists(
    select NU from PUF where (
      U.NU=PUF.NU
      and PUF.NF!=3
    )
  )
);

18)

select NU from U where(
  U.NU in (select NU from PUF)
  and not exists(
    select * from PUF where(
      U.NU=PUF.NU
      and PUF.NP not in(
        select NP from PUF where NF=1
      )
    )
  )
);



