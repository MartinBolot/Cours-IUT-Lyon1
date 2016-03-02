set serveroutput on;
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
