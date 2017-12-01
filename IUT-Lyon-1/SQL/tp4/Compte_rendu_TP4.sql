Compte rendu TP4 SQL :
1)

Creation table recolte 
create table recolte(
  nvrec number not null,
  refprod number not null,
  datrec date,
  qtrec number default 10 not null,
  
  constraint pk_recolte primary key(nvrec,refprod,datrec)
);
Création table producteurs
create table producteurs(
  refprod number not null,
  nomprod varchar2(12) default 'default' not null,
  region varchar2(10) default 'default' not null,
  
  constraint pk_producteurs primary key(refprod)
);

Création table vins
create table vins(
  nvin number not null,
  nomcru varchar2(10) not null,
  annee number default 1981 not null,
  degres real,
  prix number,
  
  constraint pk_vins primary key(nvin),
  constraint annee_vins check(annee>1980)
);

Création table achats:
create table achats(
  nvin number not null,
  nachet number not null,
  qte number default 1 not null,
  cpt number,
  
  constraint pk_achats primary key(cpt),
  constraint qte_achats check(qte>0)
);
Création table acheteurs
create table acheteurs(
  numach number not null,
  nomach varchar2(10) not null,
  typbuv varchar2(5) default 'petit' not null,
  
  constraint pk_acheteurs primary key(numach),
  constraint typ_acheteurs check(lower(typbuv) in ('gros','petit','moyen'))
);

On ajoute les relations de clés étrangères :
alter table recolte add(
  constraint fk_refprod foreign key(refprod) references producteurs(refprod),
  constraint fk_nvrec foreign key(nvrec) references vins(nvin)
);
alter table achats add(
  constraint fk_nvin foreign key(nvin) references vins(nvin),
  constraint fk_nachet foreign key(nachet) references acheteurs(numach)
);

2)
On ajoute les valeurs dans la table vins ;
insert into vins values(
    1,'St Amour',1983,11.500,31.00
); etc…

On ajoute les valeurs dans la table acheteurs:
insert into acheteurs values(
  1,'Hardy','GROS'
); etc…

On ajoute les valeurs dans la table producteurs :
insert into producteurs values(
  1,'Knock','BEAUJOLAIS'
); etc …

On ajoute les valeurs dans recolte :
insert into recolte values(
  1,1,'15/09/1983',62
); etc …

On ajoute les valeurs dans achats:
insert into achats values(
  1,9,12,1
); etc…





3)
3.1)
 select * from vins order by nomcru;

3.2) 
select distinct region from producteurs;

3.3)
select refprod,nomprod from producteurs where(
  lower(region)='savoie'
  or lower(region)='beaujolais'
);

3.4)
select nomach as "sobre" from acheteurs where(
  lower(typbuv)='petit'
);

3.5)
select vins.nvin as "vin",nachet from vins,achats where(
  vins.nvin=achats.nvin
) order by nachet desc,vins.nvin asc;









3.6)
create table jeune(
  nomcru varchar2(10) not null,
  degre real,
  
  constraint pk_jeune primary key(nomcru,degre)
);

insert into jeune(
  select nomcru,degres from vins where(
    annee>1985
  )
);

4)
4.1)
select distinct acheteurs.numach from acheteurs,achats,vins where(
  acheteurs.numach=achats.nachet
  and achats.nvin=vins.nvin
  and vins.prix>30
) order by acheteurs.numach asc;

4.2)
select vins.nomcru,producteurs.nomprod,producteurs.region from recolte,vins,producteurs where(
  recolte.nvrec=vins.nvin
  and recolte.refprod=producteurs.refprod
  and recolte.qtrec>100
);

4.3)
select distinct vins.nomcru from producteurs,recolte,vins where(
  producteurs.refprod=recolte.refprod
  and recolte.nvrec=vins.nvin
  and lower(producteurs.region)='bourgogne'
);

4.4)
select count(*) as "buveurs moyens" from acheteurs where(
  lower(typbuv)='moyen'
);





4.5)
select count(nvin) as "nombre achats", sum(qte) "quantite totale" from achats where(
  nvin=7
);

4.6)
select sum(vins.prix) as "prix hardy" from acheteurs,achats,vins where(
  acheteurs.numach=achats.nachet
  and achats.nvin=vins.nvin
  and lower(nomach)='hardy'
);






4.7)
select avg(vins.prix) from acheteurs,achats,vins where(
  acheteurs.numach=achats.nachet
  and achats.nvin=vins.nvin
  and acheteurs.numach=9
);

4.8)
select producteurs.nomprod from producteurs,recolte where(
  producteurs.refprod=recolte.refprod
  and recolte.qtrec=45
);

4.9)
select distinct acheteurs.nomach from acheteurs,achats where(
  acheteurs.numach=achats.nachet
  and achats.nvin in (1,7,12)
);

4.10)
select nvin from vins where(
  nvin not in(
    select distinct nvin from achats
  )
);






4.11)
select distinct vins.nomcru from acheteurs,achats,vins where(
  acheteurs.numach=achats.nachet
  and achats.nvin=vins.nvin
  and vins.annee<1984
  and lower(acheteurs.typbuv)!='petit'
);

4.12)
select acheteurs.numach from acheteurs,achats where(
  acheteurs.numach=achats.nachet
) group by acheteurs.numach having (
    sum(achats.qte) > (
      select avg(sum(qte)) from achats group by nachet
    )
) order by acheteurs.numach asc;

4.13)
select achats.nachet from achats,vins where(
  achats.nvin=vins.nvin
)
minus
select achats.nachet from achats,vins where(
  achats.nvin=vins.nvin
  and lower(vins.nomcru)='st amour'
);

ou
select distinct achats1.nachet from achats achats1 where(
    not exists(
      select achats.nachet from achats,vins where(
      achats1.nachet=achats.nachet
      and achats.nvin=vins.nvin
      and lower(vins.nomcru)='st amour'
    )
  )
);

