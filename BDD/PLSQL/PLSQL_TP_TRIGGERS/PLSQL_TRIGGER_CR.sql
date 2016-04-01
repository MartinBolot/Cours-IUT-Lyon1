1)

    create or replace trigger auto_increment
    before insert
    on emp  --ici emp est TABL (table) --
    for each row
    declare
      v_newId emp.empno%type;
    begin

      select max(decode(empno,null,0,0)) into v_newId from emp;  --ici empno est CLENUM (cle primaire) --
      if v_newId is null then
        v_newId:=0;
      end if;

      v_newId := v_newId+1;
      dbms_output.put_line(v_newId);
      :NEW.empno:=v_newId;
    end;
    /

2)
    create or replace trigger dept_conjoint
    before insert on customer
    for each row
    begin
      --test par rapport au CP
      if :new.cp is not null
        then
          if(
            SUBSTR(:new.cp,0,2)!='01'
            and SUBSTR(:new.cp,0,2)!='07'
            and SUBSTR(:new.cp,0,2)!='26'
            and SUBSTR(:new.cp,0,2)!='38'
            and SUBSTR(:new.cp,0,2)!='42'
            and SUBSTR(:new.cp,0,2)!='69'
            and SUBSTR(:new.cp,0,2)!='73'
            and SUBSTR(:new.cp,0,2)!='74'
          )
            then
              raise_application_error(-20001,'Le departement n''est pas valide - accepte : 01,07,26,38,42,69,73,74');
          end if;
      end if;
      -- tests par rapport au conjoint
      if :new.conjoint is not null and :new.nom is not null
        then
          if (:new.conjoint!=:new.nom)
            then
              raise_application_error(-20001,'Le client et son conjoint doivent avoir le meme nom');
          end if;
      end if;
    end;
    /

3)
    create or replace trigger log_action
    after insert or update or delete
    on dept
    declare
    v_timestamp timestamp;
    v_user varchar2(50);
    v_action varchar2(50);
    begin

        select current_timestamp into v_timestamp from dual;
        select user into v_user from dual;

        if(INSERTING) then
          v_action:='inserting';
        elsif(UPDATING) then
          v_action:='updating';
        elsif(DELETING) then
          v_action:='deleting';
        end if;

    insert into journal values(v_timestamp,v_user,'dept',v_action);
    end;
    /
