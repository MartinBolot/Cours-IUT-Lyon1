#include "ornithorynque.h"
#include "string.h"
#include <iostream>
using namespace std;

//construc
Ornithorynque::Ornithorynque():Mammifere(),Ovipare(){
    _nbOeufs=2;
    strcpy(_couleurBec,"noir");
}
Ornithorynque::Ornithorynque(
    int nbOeufs,
    char *couleurBec,
    //mamifere
    char *cri,
    //ovipare
    bool eclos,
    int anneeNaissance,
    bool vivant,
    float poids,
    float taille
):Mammifere(cri,anneeNaissance,vivant,poids,taille),Ovipare(eclos,anneeNaissance,vivant,poids,taille){
    _nbOeufs=nbOeufs;
    strcpy(_couleurBec,couleurBec);
}
Ornithorynque::~Ornithorynque(){};

//getters
int Ornithorynque::getNbOeufs(){
    return _nbOeufs;
}
char* Ornithorynque::getCouleurBec(){
    return _couleurBec;
}
//setters
void Ornithorynque::setNbOeufs(int nbOeufs){
    _nbOeufs = nbOeufs;
}
void Ornithorynque::setCouleurBec(char* couleurBec){
    strcpy(_couleurBec,couleurBec);
}
//methods
void Ornithorynque::afficheCarac(){
    cout<<"Nombre d'oeufs : "<<_nbOeufs<<endl;
    cout<<"Couleur bec : "<<_couleurBec<<endl;
    cout<<"Cri : "<<this->getCri()<<endl;
    Ovipare::afficheCarac();
}
