#pragma once
#include "ovipare.h"

class Reptile : public Ovipare{
    public:
        Reptile();
        Reptile(
            char *couleurEcailles,
            bool venimeux,
            bool eclos,
            int anneeNaissance,
            bool vivant,
            float poids,
            float taille
        );
        ~Reptile();
        //getters
        char* getCouleurEcailles();
        bool getVenimeux();
        //setters
        void setCouleurEcailles(char *couleurEcailles);
        void setVenimeux(bool venimeux);
        //methodes
        void afficheCarac();
    private:
        char _couleurEcailles[50];
        bool _venimeux;
};
