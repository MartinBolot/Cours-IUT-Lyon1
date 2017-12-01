--1)
--a)
set serveroutput on;
DECLARE
  v_num emp.empno%TYPE;
  v_moyenne NUMBER(20,10);
BEGIN
  v_num = &v_num;
  select avg(emp.sal) INTO v_moyenne
  FROM emp
  WHERE emp.job=(
    select job from emp where empno=v_num
  );

  DBMS_OUTPUT.PUT_LINE(v_moyenne);
END;

--b)
set serveroutput on
DECLARE
  v_num emp.empno%TYPE;
  v_sal emp.sal%TYPE;
  v_moyenne NUMBER(20,10);
BEGIN
  v_num = &v_num;

  select avg(emp.sal) INTO v_moyenne
  FROM emp
  WHERE emp.job=(
    select job from emp where empno=v_num
  );
  select sal into v_sal from emp where empno=v_num;

  IF v_salv_moyenne THEN
    update emp set sal=v_moyenne where empno=v_num;
  ELSE
    update emp set sal=(sal+(sal0.1)) where empno=v_num;
  END IF;

  DBMS_OUTPUT.PUT_LINE(v_moyenne);
  commit;
END;

--2)
set serveroutput on
DECLARE
  v_number NUMBER(10,2);
  v_facto NUMBER(10,2);
BEGIN
  v_number = &v_facto;
  v_facto = 1;
  while v_number0 LOOP
    v_facto = v_factov_number;
    v_number = v_number-1;
  END LOOP;
  DBMS_OUTPUT.PUT_LINE(v_facto);

  commit;
END;

-----
--3)
--a)
alter table emp add(
  budget number(10,2)
);

--b)

-----
--4)
create table personnel(
  identifiant number(5),
  nom varchar2(50),
  role varchar2(100),

  constraint pk_personnel Primary Key(identifiant)
);

set serveroutput on
DECLARE
  v_nuplet NUMBER(3);
  v_jong NUMBER(3);
  v_pourcentage NUMBER(10,7);
BEGIN
  v_nuplet=0;
  v_jong=0;
  v_pourcentage=0;

  select count(*) into v_nuplet
  from personnel;

  select count(*) into v_jong
  from personnel
  where lower(role)='jongleur';

  v_pourcentage = (v_jong100)v_nuplet;

  DBMS_OUTPUT.PUT_LINE('nombre tuples  '  v_nuplet  ', nombre de jongleurs  '  v_jong  ', pourcentage  '  v_pourcentage);
END;

set serveroutput on
DECLARE
  v_nuplet NUMBER(3);
  v_jong NUMBER(3);
  v_pourcentage NUMBER(10,7);
  empty_exception EXCEPTION;
BEGIN
  v_nuplet=0;
  v_jong=0;
  v_pourcentage=0;

  select count(*) into v_nuplet
  from personnel;

  IF v_nuplet=0 THEN
    RAISE empty_exception;
  END IF;

  select count() into v_jong
  from personnel
  where lower(role)='jongleur';

  v_pourcentage = (v_jong100)v_nuplet;

  DBMS_OUTPUT.PUT_LINE('nombre tuples  '  v_nuplet  ', nombre de jongleurs  '  v_jong  ', pourcentage  '  v_pourcentage);

  EXCEPTION
    WHEN empty_exception THEN
      dbms_output.put_line('Erreur fatale !');
    WHEN others THEN
      dbms_output.put_line('Erreur');
END;
