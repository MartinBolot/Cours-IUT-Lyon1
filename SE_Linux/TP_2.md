Exercice 1

cd $home
ls -lR

find

Exercice 2

cd $home
ls -l > essai
tr -s " " > temp < essai
cut -f9,9 -d" " < temp
rm essai temp
ls -l | tr -s " " | cut -f9,9 -d" "

Exercice 3

file ./* | grep -c "directory"
ls /usr/bin | grep -c ".h$"
ls -l | grep "^d*"

Exercice 4

ls -l | sort -n -k6,6
sort -t";" -d -k1,1 -k2,2r < perso > perso_tri
split -l10 perso_tri
sort -um xa*

Exercice 5

cut -d":" -f1,3 < annuaire
grep "toto" < annuaire | cut -d":" -f3
sort -d -k1,1 < annuaire
grep -v "^toto" < annuaire > annuaire2
grep ":rome:" -c < annuaire
grep "^t" < annuaire
