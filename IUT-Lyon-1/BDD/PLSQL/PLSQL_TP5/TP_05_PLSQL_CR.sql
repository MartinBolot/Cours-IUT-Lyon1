--1)

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


--2)

/*
	Il va falloir utiliser les triggers qui vont permettre d'�couter des �venements et
	de les traiter
*/

-- le trigger
create or replace trigger prelevement_auto
  after
    update on participe
    for each row
  declare
    v_newValue participe.payee%type;
    v_oldValue participe.payee%type;
  begin
    v_newValue:= :NEW.payee;
    v_oldValue:= :OLD.payee;
    dbms_output.put_line('new  : '||v_newValue||' old : '||v_oldValue);
    if v_oldValue='f' and v_newValue = 'v' then
      prelevement_automatique(:NEW.no_adherent,:NEW.no_sortie);
    end if;
  end;
  /

  --la procedure a appeler dans le trigger
 create or replace procedure prelevement_automatique(numAdherent number, numSortie number) is

  --curseurs
  cursor c_montant is
    select mt_participation
      from adherent natural join sortie
      where( no_sortie=numSortie and no_adherent=numAdherent );

  --declarations
  e_notIntable exception;
  e_notEnoughCash exception;

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
          else raise_application_error(-20001,'Violation d''une contrainte d''integrite');
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

  --tests
  update participe set payee='v' where no_adherent=1 and no_sortie=3;

 --3)


 create or replace function generer_prets(numsortie in number) return number is
   --declarations
   e_fatalError exception; --exception fatal error

   cursor c_paquetageDispo is  --curseur pour trouver le premier paquetage disponible et ses informations
     select *
       from paquetage natural join pret natural join utilise
       where date_retour is not null and no_sortie=numsortie;

   v_paquetageDispo c_paquetageDispo%rowtype;    --ligne du paquetage disponible
   v_paquetage paquetage.no_paquetage%type;      --no du paquetage
   v_adherentEnCours adherent.no_adherent%type;  --no de l'adherent
   v_caution paquetage.caution%type;             --caution du paquetage
   v_nouveauMonant adherent.credits%type;        --montant restant apres retrait de la caution

   v_testPaquetage boolean;                      --booleen pour tester le resultat non-vide de la requete

   begin
     v_testPaquetage:=false;
     for v_paquetageDispo in c_paquetageDispo loop
       v_testPaquetage:=true;
       v_paquetage:=v_paquetageDispo.no_paquetage;
       v_adherentEnCours:=v_paquetageDispo.no_adherent;
       v_caution:=v_paquetageDispo.caution;
       exit;
     end loop;

     if (v_testPaquetage=false) then
       raise_application_error(-20001,'aucun paquetage n''est disponible');
     end if;

     select (credits-v_caution) into v_nouveauMonant
       from adherent
       where no_adherent=v_adherentEnCours;

     if v_nouveauMonant > 0 then
       update adherent
         set credits = v_nouveauMonant
         where no_adherent=v_adherentEnCours;
       insert into pret values(
         SYSDATE,
         v_paquetage,
         v_adherentEnCours,
         null
       );
     else
       dbms_output.put_line(
         'Probleme de caution pour le paquetage '||v_paquetage
         ||'et l''adherent '||v_adherentEnCours
         ||'Le prêt ne pourra donc pas être réalisé pour cet adhérent.'
       );
     end if;

     dbms_output.put_line('transaction effectuee');
     dbms_output.put_line('no adherent credite: '||v_adherentEnCours||',no paquetage : '||v_paquetage);
     dbms_output.put_line('caution : '||v_caution||', nouveau montant credits adherent : '||v_nouveauMonant);
     return 0;

     exception
       when e_fatalError then
         dbms_output.put_line('transaction invalidee (erreur fatale)');
         return -1;
       when no_data_found then
         dbms_output.put_line('transaction invalidee (no data found)');
         return -1;
   end;
   /


 --tests
 declare
   v_test number(10);
 begin
   v_test:= generer_prets(2);
   v_test:= generer_prets(4);
   v_test:= generer_prets(5);
   --dbms_output.put_line(v_test);
 end;
 /
