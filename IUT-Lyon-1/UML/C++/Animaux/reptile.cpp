#include "reptile.h"
#include "string.h"
#include <iostream>
using namespace std;

//construct
Reptile::Reptile():Ovipare(){
    strcpy(_couleurEcailles,"noires");
    _venimeux = false;
}
Reptile::Reptile(
    char *couleurEcailles,
    bool venimeux,
    bool eclos,
    int anneeNaissance,
    bool vivant,
    float poids,
    float taille
):Ovipare(eclos,anneeNaissance,vivant,poids,taille){
    strcpy(_couleurEcailles,couleurEcailles);
    _venimeux = venimeux;
}
Reptile::~Reptile(){}

//getters
char* Reptile::getCouleurEcailles(){
    return _couleurEcailles;
}
bool Reptile::getVenimeux(){
    return _venimeux;
}

//setters
void Reptile::setCouleurEcailles(char* couleurEcailles){
    strcpy(_couleurEcailles,couleurEcailles);
}
void Reptile::setVenimeux(bool venimeux){
    _venimeux = venimeux;
}

//methods
void Reptile::afficheCarac(){
    cout<<"Couleur des ecailles : "<<_couleurEcailles<<endl;
    cout<<"Venimeux : "<<(_venimeux?"oui":"non")<<endl;
    Ovipare::afficheCarac();
}


