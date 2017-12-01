#pragma once
#include "vehicule.h"
#include "voiture.h"
class Parc{
    protected:
        const int maxLength=20;
        Vehicule* parc[20]={0};

    public:
        Parc();
        //Parc(Vehicule unParc);
        ~Parc();
        void affiche();
        int get_maxLength();
        //Vehicule* get_parc();
        //void set_maxLenth(int uneMaxLength);
        void add_vehicule(Vehicule* unVehicule);
        void remove_vehicule(Vehicule* unVehicule);
        void louer_voiture(Voiture* uneVoiture);
        void rendre_voiture(Voiture* uneVoiture);
};
