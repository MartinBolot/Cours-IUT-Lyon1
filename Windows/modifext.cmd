@echo off

set ext=%1
set ext2=%2

if "%1" == "" (
	echo erreur manque le premier parametre
	goto :fin
)
if "%2" == "" (
	echo erreur manque le second parametre
	goto :fin
)

set /a cpt=0
for %%a in (*.%ext%) do set /a cpt +=1

echo %cpt%

if /i %cpt% gtr 0 (
		for %%a in (*.%ext%) do ren %%a=*.%ext2%
	) else (
		echo Pas de fichier à modifier 
	)	

:fin
