--1)
create or replace procedure insertJob(jobId varchar2,jobTitle varchar2)
  is
  begin
    insert into jobs(job_id,job_title) values(jobId,jobTitle);
  end;
/

exec insertJob('AD_CEO','Chief Executive Officer');

--2)

create or replace procedure modif_job(idPoste varchar2,newIdPoste varchar2)
  is
    noData exception;
    cursor c_jobs is select * from jobs where(lower(idPoste) in lower(job_id));
    v_jobs c_jobs%rowtype;
    v_test number;
  begin
    v_test :=0;
    for v_jobs in c_jobs loop
      v_test:=v_test+1;
      update jobs
        set job_id = newIdPoste
        where(lower(idPoste) in lower(job_id));
    end loop;


    if v_test = 0 then raise noData;end if;

    exception
      when NO_DATA_FOUND then
        dbms_output.put_line('NO_DATA_FOUND');
      when noData then
        dbms_output.put_line('aucune mise à jour n''a eu lieu');
      when others then
        dbms_output.put_line(SQLERRM);

  end;
/

--3)

create or replace procedure nom_employes_chefs
  is
    cursor c_empchef is
      select emp1.employee_id as emp1id,
              emp1.first_name as emp1firstname,
              emp1.last_name as emp1lastname,
              emp1.manager_id as emp1manager,
              emp2.first_name as emp2firstname,
              emp2.last_name as emp2lastname
        from employees emp1,employees emp2
        where(emp1.manager_id = emp2.employee_id);
    v_empchef c_empchef%rowtype;
  begin
   for v_empchef in c_empchef loop
      dbms_output.put_line(v_empchef.emp1lastname||' -> '||v_empchef.emp2lastname||'');
   end loop;
  end;
/

exec nom_employes_chefs();

--4)

create or replace procedure plus_haut_salaire(nomEmploye varchar2)
  is
    cursor c_sal is
      select last_name,salary*(1+commission_pct) as salairetotal
        from employees emp1
        where(
          (salary*(1+commission_pct))>(
            (
              select max(salary*(1+decode(commission_pct,null,0,0)))
              from employees
              where lower(nomEmploye) = lower(last_name)
            )
          )
        );

    v_sal c_sal%rowtype;
  begin
   for v_sal in c_sal loop
      dbms_output.put_line(v_sal.last_name);
   end loop;
  end;
/

exec plus_haut_salaire('Austin');

--5)

create or replace procedure meme_job_ou_salsup(nomEmploye1 varchar2,nomEmploye2 varchar2)
  is
    cursor c_mjos is
      select * from employees where(
        lower(job_id) = (select lower(job_id) from employees where(lower(last_name)=lower(nomEmploye1)))
        or salary*(1+decode(commission_pct,null,0,0)) > (
          select max(salary*(1+decode(commission_pct,null,0,0))) from employees where lower(last_name)=lower(nomEmploye2)
        )
      );
    v_mjos c_mjos%rowtype;

  begin
    for v_mjos in c_mjos loop
      dbms_output.put_line('test');
    end loop;
  end;
/

--6)

create or replace procedure n_sal_sup(n number)
  is
    cursor c_salsup is
      select last_name,(salary*(1+decode(commission_pct,null,0,0))) as salaire
        from employees
        order by salaire desc;
    v_salsup c_salsup%rowtype;
  begin
    for v_salsup  in c_salsup loop
      dbms_output.put_line(v_salsup.last_name||' '||v_salsup.salaire);
      exit when c_salsup%rowcount>=n;
    end loop;
  end;
/

--7)

create or replace procedure affiche_deptvides
  is
    cursor c_deptvide is
        select department_id from departments where(
           not exists (
            select department_id from employees where(department_id=departments.department_id)
          )
        ) order by department_id asc;
    v_deptvide c_deptvide%rowtype;
  begin
    for v_deptvide  in c_deptvide loop
      dbms_output.put_line(v_deptvide.department_id);
    end loop;
  end;
/

--8)

create or replace procedure affiche_hierarchie(numEmploye number)
  is
    cursor c_hierarchie is
      select employee_id,last_name from employees order by employee_id;

    v_hierarchie c_hierarchie%rowtype;
  begin
    for v_hierarchie in c_hierarchie loop
      if(v_hierarchie.employee_id >= numEmploye) then
        dbms_output.put_line(v_hierarchie.employee_id||' '||v_hierarchie.last_name);
      end if;
    end loop;
  end;
/

--9)

create view myView as
  select department_id,sum((salary*(1+decode(commission_pct,null,0,0)))) as salaire
    from employees natural join departments
    group by department_id
    order by department_id;

create or replace procedure affiche_numdept(sommeMaximum number)
  is
    cursor c_sommemax is
      select * from myView;

    v_sommemax c_sommemax%rowtype;
  begin
    for v_sommemax in c_sommemax loop
      if(v_sommemax.salaire <= sommeMaximum) then   /*ici on a considere qu il fallait afficher ce qui est inferieur a la somme max contrairement a l ennonce*/
        dbms_output.put_line('Departement : '||v_sommemax.department_id||' -> somme salaires : '||v_sommemax.salaire);
      end if;
    end loop;
  end;
/

--10)

create or replace procedure depasse_salmoyen
  is
    cursor c_salmoyen is
      select last_name,department_id,(salary*(1+decode(commission_pct,null,0,0))) as salaire
        from employees emp
        where(
          (
            salary*(1+decode(commission_pct,null,0,0))) > (
              select avg((salary*(1+decode(commission_pct,null,0,0)))) as salaireMoyen
              from employees
              group by department_id
              having department_id = emp.department_id
            )
        ) order by department_id;

    v_salmoyen c_salmoyen%rowtype;
  begin
    for v_salmoyen in c_salmoyen loop
      dbms_output.put_line('Employee : ' ||v_salmoyen.last_name||', department '||v_salmoyen.department_id|| ' -> salary : '||v_salmoyen.salaire);
    end loop;
  end;
/

--11)

-- a) fonction
create or replace function check_sal(idEmployee number) return boolean is
    cursor c_salemployee is
      select last_name,department_id,(salary*(1+decode(commission_pct,null,0,0))) as salaire
        from employees emp
        where(
              salary*(1+decode(commission_pct,null,0,0)) > (
                select avg((salary*(1+decode(commission_pct,null,0,0)))) as salaireMoyen
                from employees
                group by department_id
                having department_id = emp.department_id
              )
              and employee_id = idEmployee
          ) order by department_id;

      v_salemployee c_salemployee%rowtype;
      v_test boolean;
  begin
    v_test:=false;
    for v_salemployee in c_salemployee loop
      v_test:=true;
      return true;
    end loop;
    if v_test=false then raise NO_DATA_FOUND;
    end if;
    return false;

    exception
      when NO_DATA_FOUND then
        return NULL;
  end;
/

-- b) bloc anonyme de test
declare
  v_test boolean;
begin
  v_test:=check_sal(100);
  case v_test
    when true then
      dbms_output.put_line('Salaire > moyenne des salaires');
    when false then
      dbms_output.put_line('Salaire < moyenne des salaires');
    else
      dbms_output.put_line('La fonction a renvoyé NULL à cause d''une exception');
  end case;
end;
