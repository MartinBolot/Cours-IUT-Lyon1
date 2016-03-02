#pragma once
class Vehicule
{
    protected :
        char Matricule[9];
        int Annee;
        int Km;
        int Puissance;

    public :
        Vehicule();
        Vehicule (char Unmatricule[], int UneAnnee, int UnKm, int UnePuissance);
        ~Vehicule();
        virtual void affiche();
        char* get_Unmatricule();
        int get_UneAnnee();
        int get_UnKm();
        int get_UnePuissance();
        void set_Unmatricule(char Unmatricule[]);
        void set_UneAnnee(int UneAnnee);
        void set_UnKm(int UnKm);
        void set_UnePuissance(int UnePuissance);
};
