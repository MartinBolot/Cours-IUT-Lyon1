#include <stdlib.h>
#include <ctype.h>

int main(){
    int ok;
    double fortuneEuro=0,fortuneZD=0;

    do{
        printf("Entrez votre fortune en euros : ");
        ok = scanf("%lg",&fortuneEuro);
    }while(!ok);

    fortuneZD = fortuneEuro*409929;

    printf("Votre fortune au zimbabwe s'eleve a %10.1f",fortuneZD);

    return 0;
}
