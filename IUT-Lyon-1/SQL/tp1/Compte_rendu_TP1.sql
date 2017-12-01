Martin BOLOT

SQL
Compte rendu TP1

1)
select distinct job from td1_emp;
2)
select ename,job,sal from td1_emp where (deptno=20 and sal>2000);
3)
select ename from td1_emp where (job='MANAGER' or job='PRESIDENT');
4)
select ename from td1_emp where (sal>1200 and sal<1400);
5)
select ename from td1_emp where job in('CLERK','ANALYST','SALESMAN');
6)
select ename from td1_emp where ename like 'M%';
7)
select ename from td1_emp where ename like '____N';
8)
select ename from td1_emp where ename not like '_____';
9)
select ename from td1_emp where comm is NULL;
10)
Pour avoir l’ordre par salaire croissant:
select ename from td1_emp where deptno=30 order by sal asc; 
Pour avoir l’ordre par salaire décroissant:
select ename from td1_emp where deptno=30 order by sal desc; 
11)
select ename from td1_emp where deptno=30 order by job asc,sal desc;
12)
select ename from td1_emp order by decode(comm,null,0,comm) asc;
ou 
select ename from td1_emp where(comm is not null) order by comm  asc;
13)
select ename from td1_emp order by decode(comm,null,0,comm) desc;
ou 
select ename from td1_emp where(comm is not null) order by comm  desc;

14)
select loc from td1_emp,td1_dept where(
    td1_emp.deptno = td1_dept.deptno
    and td1_emp.ename='ALLEN'
);

17)
select td1_dept.deptno from td1_dept
minus
select td1_dept.deptno from td1_emp,td1_dept where(
  td1_emp.deptno = td1_dept.deptno
);

18)
select td1_emp.*,td1_dept.dname from td1_emp,td1_dept where(
  td1_emp.deptno = td1_dept.deptno
  and td1_dept.loc='CHICAGO'
);
19)
select employe.ename,employe.sal,manager.ename,manager.sal from td1_emp manager,td1_dept,td1_emp employe where(
  manager.deptno=td1_dept.deptno
  and employe.deptno=manager.deptno
  and manager.job='MANAGER'
  and employe.job!='MANAGER'
  and manager.sal<employe.sal
);

20)
select emp2.ename from td1_emp emp1,td1_emp emp2 where(
  emp1.ename='JONES'
  and emp1.sal<emp2.sal
);
21)
select td1_emp.ename,td1_salgrade.grade from td1_emp,td1_salgrade where (
  td1_emp.sal<td1_salgrade.hisal
  and td1_emp.sal>td1_salgrade.losal
);
22)
select emp2.ename,emp2.job from td1_emp emp1,td1_emp emp2 where(
  emp1.ename='JONES'
  and emp2.job=emp1.job
);

23)
select emp2.ename from td1_emp emp1,td1_emp emp2 where(
  emp1.deptno=30
  and emp2.sal>emp1.sal
)
intersect
select ename from td1_emp;

24)
select emp2.ename from td1_emp emp1,td1_emp emp2 where(
  emp1.sal in (
    select max(td1_emp.sal)from td1_emp where(td1_emp.deptno=30)
  )
  and emp2.sal>emp1.sal
);

25)
select emp2.ename from td1_emp emp1,td1_emp emp2 where(
  emp1.deptno=30
  and emp2.deptno=10
  and emp1.job=emp2.job
);

26)

select emp2.ename,emp2.job,emp2.sal from td1_emp emp1,td1_emp emp2 where(
  emp1.ename='FORD'
  and emp1.job=emp2.job
)
minus
select ename,job,sal from td1_emp where(ename='FORD');

27)
select distinct emp2.ename,emp2.job,emp2.deptno,emp2.sal from td1_emp emp1,td1_emp emp2 where(
  (
    emp1.ename='JONES'
    and emp2.ename!='JONES'
    and emp1.job=emp2.job
  )
  or
  (
    emp1.ename='FORD'
    and emp2.ename!='FORD'
    and emp1.sal<=emp2.sal
  )
) order by job asc, sal desc;

On est obligé de sélectionner également le salaire si on veut appliquer le tri par salaires décroissants.

28)
select emp2.ename from td1_emp emp1, td1_dept dept, td1_emp emp2 where(
  emp1.deptno=dept.deptno
  and dept.dname='SALES'
  and emp2.deptno=10
  and emp2.job=emp1.job
);

29)
select emp1.ename from td1_emp emp1, td1_dept dept, td1_emp emp2 where(
  emp1.deptno=dept.deptno
  and dept.loc='CHICAGO'
  and emp2.job=emp1.job
  and emp2.ename='ALLEN'
  and emp1.ename!='ALLEN'
) order by ename asc;

30)
select emp1.ename from td1_emp emp1 where( 
  sal>(
    select avg(sal)from td1_emp where (emp1.deptno=deptno)
  )
);

