#include "ovipare.h"

class Oiseau : public Ovipare{
    public:
        Oiseau();
        Oiseau(
            int aile,
            bool vol,
            bool eclos,
            int anneeNaissance,
            bool vivant,
            float poids,
            float taille
        );
        ~Oiseau();
        //getters
        int getAile();
        bool getVol();
        //setters
        void setAile(int aile);
        void setVol(bool vol);
        //methods
        void afficheCarac();
    private:
        int _aile;
        bool _vol;
};
