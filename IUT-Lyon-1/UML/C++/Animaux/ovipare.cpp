#include "ovipare.h"
#include <iostream>
using namespace std;

//construc
Ovipare::Ovipare():Animal(){
    _eclos=true;
}
Ovipare::Ovipare(
    bool eclos,
    int anneeNaissance,
    bool vivant,
    float poids,
    float taille
):Animal(anneeNaissance,vivant,poids,taille){
    _eclos = eclos;
}
Ovipare::~Ovipare(){};
//getters
bool Ovipare::getEclos(){
    return _eclos;
}
//setters
void Ovipare::setEclos(bool eclos){
    _eclos = eclos;
}
//methods
void Ovipare::afficheCarac(){
    cout<<"Eclos : "<<( _eclos ? "oui" : "non" )<<endl;
    Animal::afficheCarac();
}
void Ovipare::pondre(){}
