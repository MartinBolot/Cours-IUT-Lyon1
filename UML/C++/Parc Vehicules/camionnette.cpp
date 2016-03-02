#include "camionnette.h"
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

Camionnette::Camionnette():Camion(),Voiture(){
        strcpy(marque,"Mercedes");
        strcpy(carburant,"diesel");

}
Camionnette::Camionnette(
            char* Unmatricule,
            int UneAnnee,
            int UnKm,
            int UnePuissance,
            int hauteur,
            int longueur,
            int tonnage,
            int nbPlaces,
            int nbPortes,
            char* couleur,
            bool loue,
            char* marque,
            char* carburant
):Camion(Unmatricule,UneAnnee,UnKm,UnePuissance,hauteur, tonnage, tonnage),
Voiture(Unmatricule,UneAnnee,UnKm,UnePuissance,nbPlaces,nbPortes,couleur,loue){
        strcpy(marque,marque);
        strcpy(carburant,carburant);
}
Camionnette::~Camionnette(){}
void Camionnette::affiche(){
    Camion::affiche();
    Voiture::affiche();
    cout << "marque : " << marque << endl;
    cout << "carburant : " << carburant << endl;
}
//getters
char* Camionnette::get_marque(){
    return marque;
}
char* Camionnette::get_carburant(){
    return carburant;
}
void Camionnette::set_marque(char* uneMarque){
    strcpy(marque,uneMarque);
}
void Camionnette::set_carburant(char* unCarburant){
    strcpy(carburant,unCarburant);
}
