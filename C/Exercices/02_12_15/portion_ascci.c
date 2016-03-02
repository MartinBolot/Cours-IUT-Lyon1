#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIMITESUP 255 /*127 sous unix, 255 sous windows*/

char controle_saisie(char* str);

int main(){
    int ok,d,f,i;
    char rep;
    int choix;

    do{
        printf("\nAFFICHAGE DU SYSTEME DE CODAGE ASCII PAR PORTION \n");
        do{
            printf("Entrer un numero de debut de 32 a %d : ",LIMITESUP);
            ok=scanf("%d",&d);
            while(getchar()!='\n');
            controle_saisie(&d);
        }
        while(!d || d<32 || d>LIMITESUP);
        do{
            printf("Entrer un numero de fin de 64 a %d : ",LIMITESUP);
            ok=scanf("%d",&f);
            while(getchar()!='\n');
        }
        while(!ok || f<64 || f>LIMITESUP);

        printf("\tCaracter ascii    NumeroDecimal\n");
        for(i=d;i<f;i++){
            printf("\t\t%c \t\t%d \n",i,i);
            if((i-d+1)%10==0){
                printf("Appuyez sur entree pour continuer");
                while(getchar()!='\n');
            }
        }


        printf("\nRecommencer (o/n) ?");
        rep=scanf("%c",&rep);
        while(getchar()!='\n');
    }
    while(tolower(rep)!='n');

    return 0;
}

char controle_saisie(char* str){
    int i;

    i=0;
    while(str[i]!='\0'){
        printf("%d \n",str[i]);
        i++;
    }
}
