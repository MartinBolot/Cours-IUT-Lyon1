DROP TABLE IF EXISTS INFOSVM CASCADE;
DROP TABLE IF EXISTS t_e_demandeur_dem CASCADE;
DROP TABLE IF EXISTS t_e_logiciel_log CASCADE;
DROP TABLE IF EXISTS t_e_machinevirtuelle_mav CASCADE;
DROP TABLE IF EXISTS t_e_versionvm_vvm CASCADE;
DROP TABLE IF EXISTS t_j_compatibilite_com CASCADE;
DROP TABLE IF EXISTS t_j_installation_ins CASCADE;
DROP TABLE IF EXISTS t_r_plateforme_pla CASCADE;
DROP TABLE IF EXISTS t_r_systemeexploitation_sye CASCADE;
DROP TABLE IF EXISTS t_r_typesysexploitation_tse CASCADE;

/* Q1 */
DROP TYPE IF EXISTS adresse_t CASCADE;

CREATE TYPE adresse_t AS (
	rue varchar(100),
	CP char(5),
	ville varchar(100)
);

DROP TABLE IF EXISTS adresses CASCADE;

CREATE TABLE adresses (
	adresse adresse_t
) WITH OIDS;

/* Q2 */
DELETE FROM adresses;
INSERT INTO adresses VALUES(
	ROW('30 bd du 11 Novembre 1918', '69100', 'Villeurbane')
), (
	ROW('10 Avenue de l''Université', '69003', 'Lyon')
), (
	ROW('9 rue Gambettta', '69007', 'Lyon')
);

/* Q3 */
SELECT
	(adresse).rue,
	(adresse).CP,
	(adresse).ville
FROM adresses
WHERE LOWER((adresse).ville) = 'lyon';

SELECT OID, *
FROM adresses;

/* Q4 */
DROP TABLE IF EXISTS Demandeur CASCADE;
DROP TABLE IF EXISTS Vacataire CASCADE;
DROP TABLE IF EXISTS Permanent CASCADE;

-- a
CREATE TABLE Demandeur (
	Nom varchar(50),
	Prenoms varchar(50) [],
	Email varchar(80)
);

-- b
CREATE TABLE Permanent (
	NoBureau char(4)
);

-- c
DELETE FROM Permanent;
INSERT INTO Permanent VALUES(
	'Delon',
	ARRAY['Paul','Henri'],
	'paul.delon@gmail.com',
	'B310'
), (
	'Picard',
	ARRAY['Anne'],
	'anne.picard@gmail.com',
	'D220'
);

-- d
CREATE TABLE Vacataire (
	adressepro adresse_t,
	adresseperso adresse_t,
	telfixe char(10),
	entreprise varchar(100)
) INHERITS (Demandeur);
INHERITS (Demandeur);


SELECT * FROM Permanent;

-- e 
DELETE FROM Vacataire;
INSERT INTO Vacataire VALUES(
	'Durand',
	ARRAY['Jean','Robert'],
	'jean.durand@gmail.com',
	ROW('10 rue des 3 Rois', '69007', 'Lyon'),
	ROW('20 Avenue Albert Einstein','69100','Villeurbanne'),
	'0450505050',
	'INSA Lyon'
), (
	'Dupond',
	ARRAY['Alain','Vincent'],
	'alain.dupond@gmail.com',
	ROW('9 rue des 3 Rois', '69007', 'Lyon'),
	ROW('10 Avenue de l''Université','69007','Lyon'),
	'0451515151',
	'Université de Lyon'
);

SELECT * FROM Vacataire;
