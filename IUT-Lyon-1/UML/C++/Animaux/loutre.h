#pragma once
#include "mammifere.h"

class Loutre : public Mammifere{
    public:
        Loutre();
        Loutre(
            char *couleurPelage,
            char* moisHibernation,
            char *cri,
            int anneeNaissance,
            bool vivant,
            float poids,
            float taille
        );
        ~Loutre();
        //getters
        char* getCouleurPelage();
        //setters
        void setCouleurPelage(char *couleurPelage); //surcharge
        void setCouleurPelage(int couleurHexa); //surcharge
        //methods
        void afficheCarac();
    private:
        char _couleurPelage[50];
};
