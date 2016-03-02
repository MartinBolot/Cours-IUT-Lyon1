#include "voiture.h"
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

Voiture::Voiture():Vehicule(){
     nbPlaces = 4;
     nbPortes = 5;
     strcpy(couleur,"blue");
     loue = false;
}

Voiture::Voiture(
            char* Unmatricule,
            int UneAnnee,
            int UnKm,
            int UnePuissance,
            int UnNbPlaces,
            int UnNbPortes,
            char* UneCouleur,
            bool EstLoue
            ):Vehicule(Unmatricule,UneAnnee,UnKm,UnePuissance){
     nbPlaces = UnNbPlaces;
     nbPortes = UnNbPortes;
     strcpy(couleur,UneCouleur);
     loue = EstLoue;
}

Voiture::~Voiture(){


}

void Voiture::affiche(){
    Vehicule::affiche();
cout<<"nbPlaces : " << nbPlaces << endl;
cout<<"nbPortes : " << nbPortes << endl;
cout<<"couleur : " << couleur << endl;
cout<<"loue : " << loue << endl;

}

int Voiture::get_nbPlaces(){
    return nbPlaces;
}

int Voiture::get_nbPortes(){
    return nbPortes;
}

char* Voiture::get_couleur(){
    return couleur;
}

bool  Voiture::get_loue(){
    return loue;
}

void Voiture::set_nbPlaces(int unNbPlaces){
    nbPlaces=unNbPlaces;
}

void Voiture::set_nbPortes(int unNbPortes){
    nbPortes=unNbPortes;
}

void Voiture::set_couleur(char* uneCouleur){
    strcpy(couleur,uneCouleur);
}

void Voiture::set_loue(bool loc){
    loue=loc;
}




