1)
create or replace procedure insertJob(jobId varchar2,jobTitle varchar2)
  is
  begin
    insert into jobs(job_id,job_title) values(jobId,jobTitle);
  end;
/

exec insertJob('AD_CEO','Chief Executive Officer');

2)

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

3)

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

4)

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
