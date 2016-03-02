#include "camion.h"
#include "voiture.h"
class Camionnette: public Camion, public Voiture{
    private:
        char marque[15];
        char carburant[15];
    public:
        Camionnette();
        Camionnette(
            char* Unmatricule,
            int UneAnnee,
            int UnKm,
            int UnePuissance,
            int hauteur,
            int longueur,
            int tonnage,
            int nbPlaces,
            int nbPortes,
            char* couleur,
            bool loue,
            char* marque,
            char* carburant
        );
        ~Camionnette();
        virtual void affiche();
        char* get_marque();
        char* get_carburant();
        void set_marque(char* uneMarque);
        void set_carburant(char* unCarburant);


};

