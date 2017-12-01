#pragma once
#include "vehicule.h"
class Voiture : public Vehicule{
    private :
        int nbPlaces;
        int nbPortes;
        char couleur[15];
        bool loue;
    public :
        Voiture();
        Voiture(
            char* Unmatricule,
            int UneAnnee,
            int UnKm,
            int UnePuissance,
            int UnNbPlaces,
            int UnNbPortes,
            char* UneCouleur,
            bool EstLoue
        );
        ~Voiture();
        void affiche();
        int get_nbPlaces();
        int get_nbPortes();
        char* get_couleur();
        bool get_loue();
        void set_nbPlaces(int unNbPlaces);
        void set_nbPortes(int unNbPortes);
        void set_couleur(char* uneCouleur);
        void set_loue(bool loc);
};
