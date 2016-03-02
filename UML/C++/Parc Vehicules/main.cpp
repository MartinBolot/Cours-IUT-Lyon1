#include "vehicule.h"
#include "voiture.h"
#include "camion.h"
#include "camionnette.h"
#include "parc.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    /*test1*/

    Vehicule* parc[4];
    Voiture* voit_1 = new Voiture;
    Voiture* voit_2 = new Voiture;
    Vehicule* vehic_1 = new Vehicule;
    Camion* camion_1 = new Camion;
    Camionnette* camionnette_1 = new Camionnette;

    Voiture* test = new Voiture("11111111",1,1,1,1,1,"color",false);

    Parc parc_1;
    parc_1.add_vehicule(test);
    parc_1.louer_voiture(test);
    parc_1.affiche();
    parc_1.rendre_voiture(test);
    parc_1.affiche();

    //camionnette_1->affiche();

    system("pause");

    return 0;
}
