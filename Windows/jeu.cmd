@echo off
set nbcoups=5
set /a x=%RANDOM%%%20
:debut
if /i %nbcoups% ==0 (
	@echo Vous avez perdu !
	pause
)

echo Trouvez le nombre x en %nbcoups% coups. Il est compris entre 0 et 20 !
set /p nb_joueur= Votre nombre :
if /i %nb_joueur% equ %x% (
	echo Bravo ! Vous avez trouve le Nombre Mystere!
	pause
) else (
	if /i %nb_joueur% lss %x% (
		echo Le nombre est plus grand !
	) else (
		echo le nombre est plus petit !
	)
	set /a nbcoups-=1
	goto:debut
)
