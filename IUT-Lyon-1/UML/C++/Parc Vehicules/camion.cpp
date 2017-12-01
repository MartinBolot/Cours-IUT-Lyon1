#include "camion.h"
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

Camion::Camion():Vehicule(){
     hauteur = 2;
     longueur = 6;
     tonnage = 4;
}

Camion::Camion(
    char* Unmatricule,
    int UneAnnee,
    int UnKm,
    int UnePuissance,
    int uneHauteur,
    int uneLongueur,
    int unTonnage
):Vehicule(Unmatricule,UneAnnee,UnKm,UnePuissance){
     hauteur = uneHauteur;
     longueur = uneLongueur;
     tonnage = unTonnage;
}

Camion::~Camion(){}

void Camion::affiche(){
    Vehicule::affiche();
    cout<<"hauteur : " << hauteur << endl;
    cout<<"longueur : " << longueur << endl;
    cout<<"tonnage : " << tonnage << endl;

}

int Camion::get_hauteur(){
    return hauteur;
}
int Camion::get_longueur(){
    return longueur;
}
int Camion::get_tonnage(){
    return tonnage;
}

void Camion::set_hauteur(int uneHauteur){
    hauteur=uneHauteur;
}
void Camion::set_longueur(int uneLongueur){
    longueur=uneLongueur;
}
void Camion::set_tonnage(int unTonnage){
    tonnage=unTonnage;
}





