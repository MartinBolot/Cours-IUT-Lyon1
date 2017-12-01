#include "animal.h"
#include <iostream>
using namespace std;

/*construct-destruct*/
Animal::Animal(){
    _idIndividu=0;
    _anneeNaissance=0;
    _vivant=true;
    _poids=1;
    _taille=1;
}
Animal::Animal(int annee,bool vivant, float poids, float taille){
    _anneeNaissance = annee;
    _vivant = vivant;
    _poids = poids;
    _taille = taille;
}
Animal::~Animal(){}

/*getters*/
int Animal::getAnneeNaissance(){
    return _anneeNaissance;
}
bool Animal::estEnVie(){
    return _vivant;
}
float Animal::getPoids(){
    return _poids;
}
float Animal::getTaille(){
    return _taille;
}

/*setters*/
void Animal::setAnneNaissance(int annee){
    if(annee>0){
        _anneeNaissance = annee;
    }
}
void Animal::setVivant(bool vivant){
    _vivant = vivant;
}
void Animal::setPoids(float poids){
    _poids = poids;
}
void Animal::setTaille(float taille){
    _taille = taille;
}

/*methodes*/
void Animal::afficheCarac(){
    cout<<"Annee de naissance : "<< _anneeNaissance <<endl;
    cout<<"Vivant : "<< (_vivant ? "oui" : "non") <<endl;
    cout<<"Poids : "<< _poids <<endl;
    cout<<"Taille : "<< _taille <<endl;
    cout<<"-------"<<endl;
}

