#include "parc.h"
#include "camionnette.h"
#include "voiture.h"
#include "camion.h"
#include <iostream>

using namespace std;

Parc::Parc(){
    int i=0;
    Camion* camion_1 = new Camion;
    Camion* camion_2 = new Camion;
    Camionnette* camionnette_1 = new Camionnette;
    Camionnette* camionnette_2 = new Camionnette;
    Voiture* voit_1 = new Voiture;
    Voiture* voit_2 = new Voiture;
    Voiture* voit_3 = new Voiture;
    Voiture* voit_4 = new Voiture;

    parc[0] = camion_1;
    parc[1] = camion_2;
    parc[2] = voit_1;
    parc[3] = voit_2;
    parc[4] = voit_3;
    parc[5] = voit_4;
    //for(i=0;i<maxLength;i++) parc[i] = new Vehicule();
}
Parc::~Parc(){}
void Parc::affiche(){
    int i=0;
    for(i=0;i<maxLength;i++){
        if(parc[i]!=0){
            parc[i]->affiche();
            cout<<"------"<<i<<endl;
        }
    }
}
int Parc::get_maxLength(){
    return maxLength;
}
void Parc::add_vehicule(Vehicule* unVehicule){
    int i=0;
    for(i=0;i<maxLength;i++){
        if(parc[i]==0){
            parc[i] = unVehicule;
            return;
        }
    }
    cout<<"impossible d ajouter le vehicule - parc plein"<<endl;
}
void Parc::remove_vehicule(Vehicule* unVehicule){
    int i=0;
    for(i=0;i<maxLength;i++){
        if(parc[i]==unVehicule){
            parc[i]=0;
            return;
        }
    }
    cout<<"Vehicule pas present dans le parc"<<endl;
}
void Parc::louer_voiture(Voiture* uneVoiture){
    if(uneVoiture->get_loue()){
        cout<<"Location impossible"<<endl;
    }else{
        uneVoiture->set_loue(true);
    }

}
void Parc::rendre_voiture(Voiture* uneVoiture){
    if(uneVoiture->get_loue()){
        uneVoiture->set_loue(false);
    }else{
        cout<<"Restitution impossible"<<endl;
    }

}
