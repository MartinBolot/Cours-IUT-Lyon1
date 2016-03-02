#pragma once
#include "animal.h"

class Mammifere : public Animal{
    public:
        Mammifere();
        Mammifere(
            char *cri,
            int anneeNaissance,
            bool vivant,
            float poids,
            float taille
        );
        ~Mammifere();
        //getters
        char* getCri();
        //setters
        void setCri(char *cri);
        //methods
        void afficheCarac();
        void allaiter();
    protected:
        void reproduire(Mammifere *mammifere);
    private:
        char _cri[50];
};
