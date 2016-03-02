--------------------------------------------------------
--  Fichier créé - lundi-février-08-2016   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table VOL
--------------------------------------------------------

  CREATE TABLE "P1506898"."VOL" 
   (	"VOLNUM" NUMBER, 
	"PLNUM" NUMBER, 
	"AVNUM" NUMBER, 
	"VILLEDEP" VARCHAR2(100 BYTE), 
	"VILLEARR" VARCHAR2(100 BYTE), 
	"HEUREDEP" DATE, 
	"HEUREARR" DATE
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "ASPE" ;
REM INSERTING into P1506898.VOL
SET DEFINE OFF;
Insert into P1506898.VOL (VOLNUM,PLNUM,AVNUM,VILLEDEP,VILLEARR,HEUREDEP,HEUREARR) values ('1123','2','1','Lyon','Monteal',to_date('04/02/16','DD/MM/RR'),to_date('04/02/16','DD/MM/RR'));
Insert into P1506898.VOL (VOLNUM,PLNUM,AVNUM,VILLEDEP,VILLEARR,HEUREDEP,HEUREARR) values ('1256','1','5','paris','Chicago',to_date('28/02/16','DD/MM/RR'),to_date('28/02/16','DD/MM/RR'));
Insert into P1506898.VOL (VOLNUM,PLNUM,AVNUM,VILLEDEP,VILLEARR,HEUREDEP,HEUREARR) values ('7657','2','6','paris','New York',to_date('02/03/16','DD/MM/RR'),to_date('02/03/16','DD/MM/RR'));
Insert into P1506898.VOL (VOLNUM,PLNUM,AVNUM,VILLEDEP,VILLEARR,HEUREDEP,HEUREARR) values ('8798','7','8','Lyon','Toulouse',to_date('20/02/16','DD/MM/RR'),to_date('20/02/16','DD/MM/RR'));
Insert into P1506898.VOL (VOLNUM,PLNUM,AVNUM,VILLEDEP,VILLEARR,HEUREDEP,HEUREARR) values ('4444','3','3','Bordeaux','Miami',to_date('25/02/16','DD/MM/RR'),to_date('25/02/16','DD/MM/RR'));
Insert into P1506898.VOL (VOLNUM,PLNUM,AVNUM,VILLEDEP,VILLEARR,HEUREDEP,HEUREARR) values ('666','1','1','Marseille','Geneve',to_date('04/02/16','DD/MM/RR'),to_date('04/02/16','DD/MM/RR'));
Insert into P1506898.VOL (VOLNUM,PLNUM,AVNUM,VILLEDEP,VILLEARR,HEUREDEP,HEUREARR) values ('888','4','8','Geneve','Paris',to_date('11/03/16','DD/MM/RR'),to_date('11/03/16','DD/MM/RR'));
Insert into P1506898.VOL (VOLNUM,PLNUM,AVNUM,VILLEDEP,VILLEARR,HEUREDEP,HEUREARR) values ('54219','6','9','Lyon','Montreal',to_date('07/04/16','DD/MM/RR'),to_date('07/04/16','DD/MM/RR'));
--------------------------------------------------------
--  Constraints for Table VOL
--------------------------------------------------------

  ALTER TABLE "P1506898"."VOL" MODIFY ("VOLNUM" NOT NULL ENABLE);
