#include "mammifere.h"
#include "ovipare.h"

class Ornithorynque : public Mammifere,public Ovipare{
    public:
        Ornithorynque();
        Ornithorynque(
            int nbOeufs,
            char *couleurBec,
            //mamifere
            char *cri,
            //ovipare
            bool eclos,
            int anneeNaissance,
            bool vivant,
            float poids,
            float taille
        );
        ~Ornithorynque();

        //getters
        int getNbOeufs();
        char* getCouleurBec();
        //setters;
        void setNbOeufs(int nbOeufs);
        void setCouleurBec(char* couleurBec);
        //methods
        void afficheCarac();
    private:
        int _nbOeufs;
        char _couleurBec[50];
};
