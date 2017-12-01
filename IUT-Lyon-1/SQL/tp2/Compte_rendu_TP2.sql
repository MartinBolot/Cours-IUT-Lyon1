Martin BOLOT

SQL : Compte-rendu TP2



1)
select ename,job,sal,comm,(sal+decode(comm,null,0,comm)) as "total compensation" from emp where(deptno='30');

2)
On effectue d’abord la requête pour obtenir la liste des départements élevés à la puissance 2 et à la puissance 3.
select deptno,power(deptno,2) as "puissance 2",power(deptno,3) as "puissance 3",dname from dept;

On effectue ensuite la requête suivante :
select ename,sal,(sal/22) as "salaire journalier",round(sal/22) as "arrondi en dollar",trunc((sal/22),2) as "arrondi en penny" from emp where(deptno='30');

3)
select ename,sal,trunc((sal/22),2) as "salaire journalier",trunc((sal/(22*8)),2) as "salaire horaire" from emp where(deptno='30');

4)
select deptno,(dname||' - '||loc) as "dname - loc" from dept;

5)
select ename,job,decode(
    job,
    'CLERK',1,
    'MANAGER',3,
    'PRESIDENT',5,
    null,0,
    2
  ) as "code job"
from emp;.

6)
select decode(deptno,10,job,ename),deptno from emp;

7)
select substr(dname,0,5) from dept;

8)
select upper(ename) as "minuscule", lower(ename) as "majuscule" from emp;

9)
select ename,instr(ename,'R') as "premiere occurence de R" from emp;

10)
select dname,length(dname) as "nombre de caracteres" from dept;

11)
select ename,sal,RPAD('$',round(sal/100),'$') as "histogramme" from emp;

12)
select * from emp where(
  deptno=&departement
);

13)
select ename,job,TO_CHAR(hiredate,'day DD month YYYY') as "date embauche" from emp where deptno='20';

14)
select ename,hiredate from emp where(
  hiredate > TO_DATE('04-01-1981')
  and hiredate < TO_DATE('15-04-1981')
) order by hiredate asc;

15)
select
  max(sal) as "salaire le plus haut",
  min(sal) as "salaire le plus bas",
  (max(sal)-min(sal)) as "difference"
from emp;

16)
select max(length(dname)) as "caracteres nom dpt" from dept;
