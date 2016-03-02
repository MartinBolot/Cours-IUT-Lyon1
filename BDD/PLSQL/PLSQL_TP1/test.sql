DECLARE
    CURSOR c_empno is
      select empno from emp natural join dept where(
      lower(dept.loc)='dallas'
      or lower(dept.loc)='new york'
    ); 
    v_empno c_empno%rowtype;
  
  BEGIN
    OPEN c_empno;
    LOOP 
      fetch c_empno into v_empno;
      exit when c_empno%notfound;
      update emp set sal = sal+(sal*0.1) where empno=v_empno;
      DBMS_OUTPUT.PUT_LINE(v_empno);
    END LOOP;
    CLOSE c_empno;
    
  END;
  /