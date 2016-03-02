#include "chien.h"
#include "string.h"
#include <iostream>
using namespace std;

//construct
Chien::Chien():Mammifere(){
    strcpy(_robe,"noire");
    strcpy(_nomProprietaire,"inconnu");
    strcpy(_race,"inconnu");
}

Chien::Chien(
            char *robe,
            char *nomProprietaire,
            char *race,
            char *cri,
            int anneeNaissance,
            bool vivant,
            float poids,
            float taille
):Mammifere(cri,anneeNaissance,vivant,poids,taille){
    strcpy(_robe,robe);
    strcpy(_nomProprietaire,nomProprietaire);
    strcpy(_race,race);
}
Chien::~Chien(){}
//getters
char* Chien::getRobe(){
    return _robe;
}
char* Chien::getNomProprietaire(){
    return _nomProprietaire;
}
char* Chien::getRace(){
    return _race;
}
//setters
void Chien::setRobe(char* robe){
    strcpy(_robe,robe);
}
void Chien::setNomProprietaire(char* nomProprietaire){
    strcpy(_nomProprietaire,nomProprietaire);
}
void Chien::setRace(char* race){
    strcpy(_race,race);
}
//methods
void Chien::afficheCarac(){
    cout<<"Robe : "<<_robe<<endl;
    cout<<"Nom du proprietaire : "<<_nomProprietaire<<endl;
    cout<<"Race : "<<_race<<endl;
    Mammifere::afficheCarac();
}
