#include "mammifere.h"
#include "string.h"
#include <iostream>
using namespace std;

//construct
Mammifere::Mammifere():Animal(){
    strcpy(_cri,"cri");
}
Mammifere::Mammifere(
    char * cri,
    int anneeNaissance,
    bool vivant,
    float poids,
    float taille
):Animal(anneeNaissance,vivant,poids,taille){
    strcpy(_cri,cri);
}
Mammifere::~Mammifere(){}
//getters
char* Mammifere::getCri(){
    return _cri;
}
//setters
void Mammifere::setCri(char *cri){
    strcpy(_cri,cri);
}
//methods
void Mammifere::afficheCarac(){
    cout<<"Cri : "<<_cri<<endl;
    Animal::afficheCarac();
}
void Mammifere::allaiter(){}
void Mammifere::reproduire(Mammifere *mammifere){}
