#include "vehicule.h"
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

Vehicule::Vehicule()
{
    //Matricule="135QBE69";
    strcpy(Matricule,"135QBE69");
    Annee=2016;
    Km=0;
    Puissance=7;
}

Vehicule::Vehicule(char Unmatricule[], int UneAnnee, int UnKm, int UnePuissance)
{
    strcpy(Matricule,Unmatricule);
    Annee=UneAnnee;
    Km=UnKm;
    Puissance=UnePuissance;
}

Vehicule::~Vehicule()
{

}

void Vehicule::affiche()
{
    cout<<"Matricule : "<<Matricule<<endl;
    cout<<"Annee : "<<Annee<<endl;
    cout<<"Km : "<<Km<<endl;
    cout<<"Puissance : "<<Puissance<<endl;
}

char* Vehicule::get_Unmatricule()
{
    return Matricule;
}
int Vehicule::get_UneAnnee(){
    return Annee;
}
int Vehicule::get_UnKm(){
    return Km;
}
int Vehicule::get_UnePuissance(){
    return Puissance;
}

void Vehicule::set_Unmatricule(char Unmatricule[]){
    strcpy(Matricule,Unmatricule);
}
void Vehicule::set_UneAnnee(int UneAnnee){
    Annee=UneAnnee;
}
void Vehicule::set_UnKm(int UnKm){
    Km=UnKm;
}
void Vehicule::set_UnePuissance(int UnePuissance){
    Puissance=UnePuissance;
}



