#pragma once
class Animal{

    public:
        //constructeurs-desctructeurs
        Animal();
        Animal(int annee,bool vivant,float poids,float taille);
        ~Animal();
        //getters
        int getAnneeNaissance();
        bool estEnVie();
        float getPoids();
        float getTaille();
        char* getId();
        //setters
        void setAnneNaissance(int annee);
        void setVivant(bool vivant);
        void setPoids(float poids);
        void setTaille(float taille);
        //methodes
        virtual void afficheCarac();    //methode polymorphe

    private:
        const char* idIndividu;
        int _anneeNaissance=0;
        bool _vivant=true;
        float _poids=1;
        float _taille=1;

};
