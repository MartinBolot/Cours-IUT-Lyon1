create or replace procedure modif_job(idPoste varchar2,newIdPoste varchar2)
  is
    noData exception;
    cursor c_jobs is 
      select * from jobs where(lower(idPoste) in lower(job_id));
    v_jobs c_jobs%rowtype;
  begin
    if c_jobs%rowcount = 0 then raise noData;
    for v_jobs in c_jobs loop
      update jobs 
        set job_id = newIdPoste 
        where(lower(idPoste) in lower(job_id));
    end loop;
    
    exception
      when noData then
        dbms_output.put_line('no data');
      when NO_DATA_FOUND then
        dbms_output.put_line('NO_DATA_FOUND');
      /*when others then
        dbms_output.put_line(SQLERRM);*/

  end;
/

exec modif_job('','');
exec modif_job('toto','test');

rollback;

select * from jobs where('' in lower(job_id));