#pragma once
#include "mammifere.h"

class Chien : public Mammifere{
    public:
        Chien();
        Chien(
            char *robe,
            char *nomProprietaire,
            char *race,
            char *cri,
            int anneeNaissance,
            bool vivant,
            float poids,
            float taille
        );
        ~Chien();
        //getters
        char* getRobe();
        char* getNomProprietaire();
        char* getRace();
        //setters
        void setRobe(char* robe);
        void setNomProprietaire(char* nomProprietaire);
        void setRace(char* race);
        //methods
        void afficheCarac();
    private:
        char _robe[50];
        char _nomProprietaire[50];
        char _race[50];

};
