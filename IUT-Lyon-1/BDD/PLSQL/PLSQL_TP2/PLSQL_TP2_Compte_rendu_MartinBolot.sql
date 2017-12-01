--2)

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
  empty_exception EXCEPTION;
BEGIN
  v_nuplet:=0;
  v_jong:=0;
  v_pourcentage:=0;

  select count(*) into v_nuplet
  from personnel;

  IF v_nuplet=0 THEN
    RAISE empty_exception;
  END IF;

  select count(*) into v_jong
  from personnel
  where lower(role)='jongleur';

  v_pourcentage := (v_jong*100)/v_nuplet;

  DBMS_OUTPUT.PUT_LINE('nombre tuples : ' || v_nuplet || ', nombre de jongleurs : ' || v_jong || ', pourcentage : ' || v_pourcentage);

  EXCEPTION
    WHEN empty_exception THEN
      dbms_output.put_line('Erreur fatale !');
    WHEN others THEN
      dbms_output.put_line('Erreur');
END;

--3)

DECLARE
  CURSOR c_tab is select tname,tabtype from tab order by tname asc;
  v_tab c_tab%rowtype;

BEGIN
  OPEN c_tab;
  LOOP
    FETCH c_tab into v_tab;
    exit when c_tab%NOTFOUND;
    DBMS_OUTPUT.PUT_LINE('L''objet ' || v_tab.tname || ' est de type ' || v_tab.tabtype);
  END LOOP;
  close c_tab;
end;

--4)
	--2)

	DECLARE
  cursor c_vol is
    select * from vol;

  v_vol c_vol%rowtype;
  v_newtempvol NUMBER(10,4);
  v_newarrivee Date;

BEGIN
  open c_vol;
  loop
    fetch c_vol into v_vol;
    exit when c_vol%NOTFOUND;

    v_newtempvol:=0;

    IF v_vol.avnum in (1,4) THEN
      v_newtempvol:= to_number(v_vol.heurearr - v_vol.heuredep)*24*0.9;
    END IF;
    IF v_vol.avnum in (2,8) THEN
      v_newtempvol:= to_number(v_vol.heurearr - v_vol.heuredep)*24*0.85;
    END IF;

    v_newarrivee:= v_vol.heuredep+v_newtempvol/24;

    update vol set heurearr=v_newarrivee where(volnum=v_vol.volnum and avnum in (1,4,2,8));

  end loop;
  close c_vol;

END;
