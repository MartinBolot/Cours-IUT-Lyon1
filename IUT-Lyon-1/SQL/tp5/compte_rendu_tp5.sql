Compte rendu TP5
Martin BOLOT

3)
create table client (
  numClient varchar2(20) not null,
  nomClient varchar2 (20) not null,
  adresseClient varchar2 (200) not null,
  codePostalclient varchar2 (5) not null,
  villeClient varchar2 (200) not null,
  tel varchar2 (20),
  
  constraint pk_client primary key(numClient)
); 

create table bouquet(
  numBouquet varchar2(20) not null,
  nbBouquet number(4) not null,
  
  constraint pk_bouquet primary key(numBouquet),
  constraint nbBouquet check(nbBouquet>0)
);

create table ville(
  codePostal varchar(5) not null,
  ville varchar(200) not null,
  tarifLivraison real not null,
  
  constraint pk_ville primary key(codePostal)
);


create table fleur(
  nomFleur varchar(200) not null,
  tarifFleur real not null,
  
  constraint pk_fleur primary key(nomFleur)
);

create table commande(
  numCommande varchar2(20) not null,
  dateCommande date not null,
  nomLivraison varchar2(200) not null,
  adresseLivraison varchar2(200) not null,
  dateLivraisonprevue date not null,
  dateAcceptation date,
  dateLivraisonEffective date,
  datePaiement date,
  numClient varchar2(20) not null,
  numBouquet varchar2(20) not null,
  codePostal varchar2(5) not null,
  
  constraint pk_commande primary key(numCommande),
  constraint fk_numClient foreign key(numClient) references client(numclient),
  constraint fk_numBouquet foreign key(numBouquet) references bouquet(numBouquet),
  constraint fk_codePostal foreign key(codePostal) references ville(codePostal)
);

create table facture(
  numFacture varchar2(20) not null,
  dateFacture date not null,
  numCommande varchar2(20) not null,
  
  constraint pk_facture primary key(numFacture),
  constraint fk_numCommande foreign key(numCommande) references commande(numCommande)
);

create table composition(
  numBouquet varchar2(20) not null,
  nomFleur varchar2(200) not null,
  nbrFleurs number(4) not null,
  
  constraint pk_composition primary key(numBouquet,nomFleur),
  constraint fk_numBouquet2 foreign key(numBouquet) references bouquet(numBouquet),
  constraint fk_nomFleur2 foreign key(nomFleur) references fleur(nomFleur)
);

create table achat(
  nomFleur varchar2(200) not null,
  dateAchat date not null,
  prixAchat real not null,
  
  constraint pk_achat primary key(nomFleur,dateAchat),
  constraint fk_nomFleur3 foreign key(nomFleur) references fleur(nomFleur)
);

5)
R1)
select count(*) from commande where to_char(datepaiement,'YYYY')=2015;

R2)
select * from (select codepostal from commande group by codepostal order by count(codepostal) desc) where rownum<4;

R3)
select composition.nomfleur,sum(composition.nbrfleurs*bouquet.nbbouquet)
from composition 
  join bouquet on bouquet.numbouquet=composition.numbouquet
  join commande on commande.numbouquet=composition.numbouquet
where(
  to_char(commande.dateacceptation,'YYYY')=2014
)
group by composition.nomfleur having(
  sum(composition.nbrfleurs*bouquet.nbbouquet) = (
    select max(sum(composition.nbrfleurs*bouquet.nbbouquet))
      from composition 
          join bouquet on bouquet.numbouquet=composition.numbouquet
          join commande on commande.numbouquet=composition.numbouquet
      where(
          to_char(commande.dateacceptation,'YYYY')=2014
      )
      group by composition.nomfleur
    )
);

R4)
select (sum(nbbouquet)/count(distinct numclient)) as "moyenne bouquet par client" 	from commande natural join bouquet;

R5)
select nomfleur from fleur
minus
select nomfleur from composition;

R6)
select client1.nomclient,composition.nomfleur
from commande,bouquet,composition,client client1
where(
  commande.numbouquet=bouquet.numbouquet
  and composition.numbouquet=bouquet.numbouquet
  and client1.numclient = commande.numclient
)
group by composition.nomfleur,client1.nomclient
having(
  sum(bouquet.nbbouquet*composition.nbrfleurs) = (
    select max(bouquet.nbbouquet*composition.nbrfleurs)
    from commande,bouquet,composition,client
    where(
      commande.numbouquet=bouquet.numbouquet
      and composition.numbouquet=bouquet.numbouquet
      and client.numclient = commande.numclient
      and client1.nomclient = client.nomclient
    )
    group by client.numclient
  )
) order by nomclient;

R7)
create view vcom as
  select numcommande,datecommande,(sum(nbbouquet*nbrfleurs*tariffleur)) as "prix"
  from commande
    natural join bouquet
    natural join composition
    natural join fleur 
  group by numcommande,datecommande
  order by numcommande asc;
select * from vcom;

R8)
create view vcom as
  select numcommande,datecommande,numclient,nomclient,(sum(nbbouquet*nbrfleurs*tariffleur)) as "prix"
  from commande
    natural join client
    natural join bouquet
    natural join composition
    natural join fleur 
  group by numcommande,datecommande,numclient,nomclient
  order by sum(nbbouquet*nbrfleurs*tariffleur) desc;
select * from vcom where rownum=1;


