-- Q12
SELECT d.dem_nom, d.dem_prenom, COUNT(m.mav_id) FROM t_e_demandeur_dem d
	LEFT JOIN t_e_machinevirtuelle_mav m
		ON d.dem_id = m.dem_id
GROUP BY d.dem_id
ORDER BY d.dem_nom, d.dem_prenom

-- Q13
-- nombre de VM par OS et par Type d'OS
SELECT
	t.tse_nom AS "Type OS",
	s.sye_nom AS "OS",
	COUNT(m.mav_id) AS "nb VMs"
FROM t_e_machinevirtuelle_mav m
	JOIN t_r_systemeexploitation_sye s
		ON m.sye_id = s.sye_id
	JOIN t_r_typesysexploitation_tse t
		ON t.tse_id = s.tse_id
GROUP BY s.sye_id, t.tse_id
ORDER BY t.tse_nom, s.sye_nom;

-- Q14
DROP VIEW IF EXISTS v_derversionvm;
CREATE OR REPLACE VIEW v_derversionvm AS
SELECT
	m.mav_id,
	m.mav_nom,
	m.mav_description,
	MAX(v.vvm_date)
FROM t_e_machinevirtuelle_mav m
	JOIN t_e_versionvm_vvm v
		ON m.mav_id = v.mav_id
GROUP BY m.mav_id, v.vvm_date
HAVING date_part('year', v.vvm_date) = date_part('year', current_date)
ORDER BY m.mav_id;

SELECT * FROM v_derversionvm;

-- Q15
SELECT
	m.mav_id AS "ID VM",
	i.vvm_num AS "Num version",
	COUNT(i.log_id) AS "Nb logiciels",
	CASE
		WHEN  COUNT(i.log_id) = 0 THEN 'OS nu'
		WHEN  COUNT(i.log_id) BETWEEN 1 AND 2 THEN 'Peu'
		WHEN  COUNT(i.log_id) BETWEEN 3 AND 5 THEN 'Normal'
		ELSE 'Beaucoup de travail'
	END AS "qualification"
FROM t_e_machinevirtuelle_mav m
	LEFT JOIN t_e_versionvm_vvm v
		ON m.mav_id = v.mav_id
	LEFT JOIN t_j_installation_ins i
		ON i.vvm_num = v.vvm_num AND i.mav_id = v.mav_id
GROUP BY m.mav_id, i.vvm_num
ORDER BY m.mav_id;

-- Q16
DROP TABLE IF EXISTS INFOSVM;

CREATE TABLE INFOSVM AS
SELECT
	mav_id,
	mav_nom,
	mav_description,
	mav_tailledd,
	mav_ram,
	mav_typestockage,
	dem_nom,
	dem_prenom
FROM t_e_machinevirtuelle_mav m
	JOIN t_e_demandeur_dem d ON m.dem_id = d.dem_id;

SELECT * FROM INFOSVM;

-- Q17
