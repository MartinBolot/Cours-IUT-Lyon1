#include "loutre.h"
#include "string.h"
#include "stdlib.h"
#include <iostream>
using namespace std;

//construc
Loutre::Loutre():Mammifere(){
    strcpy(_couleurPelage,"marron");
}
Loutre::Loutre(
    char *couleurPelage,
    char* moisHibernation,
    char *cri,
    int anneeNaissance,
    bool vivant,
    float poids,
    float taille
):Mammifere(cri,anneeNaissance,vivant,poids,taille){
    strcpy(_couleurPelage,couleurPelage);
}
Loutre::~Loutre(){}
//getters
char* Loutre::getCouleurPelage(){
    return _couleurPelage;
}
//setters
void Loutre::setCouleurPelage(char *couleurPelage){
    strcpy(_couleurPelage,couleurPelage);
}
void Loutre::setCouleurPelage(int couleurHexa){
    char *couleurPelage;
    itoa(couleurHexa,couleurPelage,10);
    strcpy(_couleurPelage,couleurPelage);
}
//method
void Loutre::afficheCarac(){
    cout<<"Couleur du pelage : "<<_couleurPelage<<endl;
    Mammifere::afficheCarac();
}
