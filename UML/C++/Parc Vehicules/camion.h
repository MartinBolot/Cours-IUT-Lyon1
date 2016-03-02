#pragma once
#include "vehicule.h"
class Camion : public Vehicule{
    private:
        int hauteur;
        int longueur;
        int tonnage;
    public :
        Camion();
        Camion(
            char* Unmatricule,
            int UneAnnee,
            int UnKm,
            int UnePuissance,
            int hauteur,
            int longueur,
            int tonnage
        );
        ~Camion();
        void affiche();
        int get_hauteur();
        int get_longueur();
        int get_tonnage();
        void set_hauteur(int uneHauteur);
        void set_longueur(int uneLongueur);
        void set_tonnage(int unTonnage);
};
