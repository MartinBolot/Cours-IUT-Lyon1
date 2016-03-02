#pragma once
#include "oiseau.h"
#include <iostream>
using namespace std;

//construct
Oiseau::Oiseau():Ovipare(){
    _aile = 2;
    _vol = true;
}
Oiseau::Oiseau(
    int aile,
    bool vol,
    bool eclos,
    int anneeNaissance,
    bool vivant,
    float poids,
    float taille
):Ovipare(eclos,anneeNaissance,vivant,poids,taille){
    _aile = aile;
    _vol = vol;
}
//getters
int Oiseau::getAile(){
    return _aile;
}
bool Oiseau::getVol(){
    return _vol;
}
//setters
void Oiseau::setAile(int aile){
    _aile=aile;
}
void Oiseau::setVol(bool vol){
    _vol = vol;
}

//methods
void Oiseau::afficheCarac(){
    cout<<"Nombre d'ailes : "<<_aile<<endl;
    cout<<"Vole : "<<(_vol?"oui":"non")<<endl;
    Ovipare::afficheCarac();
}
