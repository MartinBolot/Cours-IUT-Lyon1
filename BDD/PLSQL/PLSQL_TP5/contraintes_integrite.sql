alter table PARTICIPE
	add constraint FK_PARTICIPE_SORTIE foreign key (NO_SORTIE)
	references SORTIE (NO_SORTIE);
alter table PARTICIPE
	add constraint FK_PARTICIPE_ADHERENT foreign key (NO_ADHERENT)
	references ADHERENT (NO_ADHERENT);
alter table PRET
	add constraint FK_PRET_ADHERENT foreign key (NO_ADHERENT)
	references ADHERENT (NO_ADHERENT);
alter table PRET
	add constraint FK_PRET_PAQUETAGE foreign key (NO_PAQUETAGE)
	references PAQUETAGE (NO_PAQUETAGE);
alter table UTILISE
	add constraint FK_UTILISE_PAQUETAGE foreign key (NO_PAQUETAGE)
	references PAQUETAGE (NO_PAQUETAGE);
alter table UTILISE
	add constraint FK_UTILISE_SORTIE foreign key (NO_SORTIE)
	references SORTIE (NO_SORTIE);