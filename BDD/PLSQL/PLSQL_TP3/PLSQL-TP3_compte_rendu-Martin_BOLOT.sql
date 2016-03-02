1)

DECLARE
  CURSOR c_emp is
    select * from emp;
  --v_emp c_emp%rowtype;
BEGIN
  FOR v_emp in c_emp LOOP
    IF (v_emp.comm!=null or v_emp.comm!=0) THEN
      DBMS_OUTPUT.PUT_LINE(
        'L''employé '||v_emp.ename ||
        ' a une commission de ' || v_emp.comm || ' dollars'
      );
    ELSE
      DBMS_OUTPUT.PUT_LINE(
        'L''employé '||v_emp.ename ||
        ' n''a pas de commission'
      );
    END IF;
  END LOOP;
END;

2)
create table employees as (select * from hr.employees);
alter table employees add(
  Etoiles varchar2(50)
);

DECLARE
  cursor c_employee is
    select * from employees;
  v_employee c_employee%rowtype;
  v_star employees.etoiles%type;
  v_sal employees.salary%type;
BEGIN
  open c_employee;
  loop
    fetch c_employee into v_employee;
    exit when c_employee%notfound;
    v_star:='';
    v_sal:=v_employee.salary;
    loop
      v_star:=v_star||'*';
      v_sal:=v_sal-1000;
      exit when v_sal<=0;
    end loop;
    update employees
      set etoiles=v_star
      where(employee_id=v_employee.employee_id);
  end loop;
  close c_employee;
END;

3)
create table departments as (select * from hr.departments);

DECLARE
  cursor
    c_depart is
      select * from departments order by department_id;
  cursor
    c_empid (p_deptid departments.department_id%type, p_empid employees.employee_id%type) is
      select * from employees where(department_id=p_deptid and employee_id<p_empid) order by employee_id;

  v_depart c_depart%rowtype;
  v_empid c_empid%rowtype;

  v_numdepart departments.department_id%type;

BEGIN
  --premier point
  /*
  open c_depart;
  v_numdepart:='';
  loop
    fetch c_depart into v_depart;
    exit when c_depart%notfound;
    if v_depart.department_id<100 then
      v_numdepart:=v_depart.department_id;
      DBMS_OUTPUT.PUT_LINE(v_numdepart);
    end if;
  end loop;
  close c_depart;
  */

  --deuxiéme point
  for  v_depart in c_depart loop
    if v_depart.department_id<100 then
      v_numdepart:=v_depart.department_id;
      DBMS_OUTPUT.PUT_LINE('Numéro departement : ' || v_numdepart || ' Nom département : ' || v_depart.department_name);
      for v_empid in c_empid(v_numdepart,120) loop
          DBMS_OUTPUT.PUT_LINE(
            '    ' ||
            v_empid.last_name|| ', '
            || v_empid.job_id|| ', '
            || v_empid.hire_date|| ', '
            || v_empid.salary
          );
      end loop;
      DBMS_OUTPUT.PUT_LINE('---------------------------------------------------------');
    end if;
  end loop;
END;
