#pragma once
#include "animal.h"

class Ovipare : public Animal{
    public:
        Ovipare();
        Ovipare(
            bool eclos,
            int anneeNaissance,
            bool vivant,
            float poids,
            float taille
        );
        ~Ovipare();
        //getters
        bool getEclos();
        //setters
        void setEclos(bool eclos);
        //methods
        void afficheCarac();
        void pondre();
    private:
        bool _eclos;
};
