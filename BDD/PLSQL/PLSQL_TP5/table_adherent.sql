create table ADHERENT (
NO_ADHERENT NUMBER(4) ,
NOM_ADHERENT VARCHAR2(30),
PRENOM_ADHERENT VARCHAR2(20),
CREDITS NUMBER(11,2)
constraint ck_adherent_credits check (credits > 0),
constraint PK_ADHERENT primary key (NO_ADHERENT)
);