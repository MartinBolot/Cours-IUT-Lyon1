@echo off
setlocal ENABLEDELAYEDEXPANSION

set pref=%1
set ext=%2
set cpt=0

if "%1" == "" (
	echo erreur manque le premier parametre
	goto :fin
)
if "%2" == "" (
	echo erreur manque le second parametre
	goto :fin
)

for %%a in (*.%ext%) do (
	set /a cpt+=1
	ren %%a %pref%!cpt!.%ext%
)

if /i %cpt% equ 0 (
		echo Pas de fichier a modifier
	)

:fin
pause
