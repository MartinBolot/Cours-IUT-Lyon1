1)

create or replace procedure alimenter_credit(numAdherent varchar2, somme number) is
  --declarations
  notInTable exception;
  v_isIdInTable number(10,2);
	begin
	  select count(*) into v_isIdInTable from adherent where no_adherent=numAdherent;
	  if v_isIdInTable <= 0 
		then raise notInTable;
		else 
			update adherent set credits = credits+somme where no_adherent=numAdherent;
			commit;
	  end if;
	  
	  exception
		when notInTable then
		  dbms_output.put_line('Erreur : ID adherent introuvable');
	end;
	/

exec alimenter_credit(9,22);


2)
 
/*
	Il va falloir utiliser les triggers qui vont permettre d'écouter des évenements et
	de les traiter
*/

-- le trigger (a completer pour appeler correctement la procedure ci-dessous)
create or replace trigger prelevement_auto
  before
    update on participe
    FOR EACH ROW
  declare
    v_newValue participe.payee%type;
    v_oldValue participe.payee%type;
  begin
    v_newValue:= :NEW.payee;
    v_oldValue:= :OLD.payee;
    dbms_output.put_line('new  : '||v_newValue||' old : '||v_oldValue);
    if v_oldValue='f' and v_newValue = 'v'
      then dbms_output.put_line('autolaunch');
    end if;
  end;
  /
  
 --la procedure a appeler dans le trigger
 create or replace procedure prelevement_automatique(numAdherent number, numSortie number) is

  --curseurs
  cursor c_montant is
    select mt_participation 
      from participe natural join adherent natural join sortie
      where( no_sortie=numSortie and no_adherent=numAdherent);
      
  --declarations
  e_notIntable exception;
  
  v_isInTable number(10,2);
  v_noDataFound boolean;
  v_montant c_montant%rowtype;
  v_creditsAdherent adherent.credits%type;
  
  begin
    v_noDataFound:=true;
    
    for v_montant in c_montant loop
      v_noDataFound:=false;
      select credits into v_creditsAdherent
        from adherent
        where no_adherent = numAdherent;
      if (v_creditsAdherent - v_montant.mt_participation)>0 then
        update adherent set credits = credits-v_montant.mt_participation where no_adherent=numAdherent;
      end if;
    end loop;
    
    if v_noDataFound=true then raise no_data_found;
    end if;
    
    exception
      when e_notIntable then
        dbms_output.put_line('Erreur : ID adherent introuvable');
      when no_data_found then
        dbms_output.put_line('Prelevement impossible - pas de participation pour ce couple (adherent,sortie)');
      
  end;
  /