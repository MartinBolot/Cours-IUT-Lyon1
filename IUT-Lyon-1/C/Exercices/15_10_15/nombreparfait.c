#include <stdlib.h>
#include <ctype.h>

typedef char bool;
#define false 0
#define true 1

void nbparfait(int nb);

int main(){
    char rep;
    int nb,ok=0;

    do{
        do{
            printf("Entrer un nb de 1 à 1000 : ");
            ok=scanf("%d",&nb);
            while(getchar()!='\n');
        }while(!ok || nb>1000 || nb<1);

        nbparfait(nb);

        printf("Voulez-vous recommencer (o/n) ? ");
        scanf("%c",&rep);
        while(getchar()!='\n');

    }while(tolower(rep)!='n');
    return 0;
}


void nbparfait(int nb){
    int sommeDiviseurs,sommeopti;
    bool hasParfait = false;

    /*printf("%d \n",nb);*/

    int i=1,j;

    while(i<nb){
        sommeopti=0;
        sommeopti=i%10;

        if(sommeopti==6 || sommeopti==8){
            j=1;
            sommeDiviseurs=3;

            for(j=3;j<=i/2;j++){
                if(i%j==0){
                    sommeDiviseurs=sommeDiviseurs+j;
                }
            }

        }
        if(sommeDiviseurs==i){
            hasParfait = true;
            printf("%d est un nombre parfait \n",i);
        }
        i++;
    }
    if(hasParfait==false){
        printf("Il n'y a pas de nombre parfait dans {1,...,%d} \n",nb);
    }
}
