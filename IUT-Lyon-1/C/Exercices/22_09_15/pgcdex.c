#include <stdio.h>
#include <ctype.h>

int pgcdi(int a, int b);
int pgcdr(int a, int b);

int main()
{
    int n=0;
    char rep;
    int a,b,ok;

    printf("Calcul du pgcd des 1 entiers a et b \n");


    do{
        rep='a';
        /*boucle pour le nombre a*/
        do{
            printf("Entrer le nombre entier a : ");
            ok=scanf("%d",&a);
            while(getchar( ) != '\n');
        }while( !ok || a<0 );
        /*boucle pour le nombre b*/
        do{
            printf("Entrer le nombre entier b : ");
            ok=scanf("%d",&b);
            while(getchar( ) != '\n');
        }while( !ok || b<0 );

        //reponse
        printf("pgcdi(%d,%d) = %d par une methode iterative \n",a,b,pgcdi(a,b));
        printf("pgcdr(%d,%d) = %d par une methode recursive \n",a,b,pgcdr(a,b));

        printf("\nRecommencer?(o/n)\n");
        rep=scanf("%c",&rep);
        while(getchar( ) != '\n');

    }while(tolower(rep) !='n');

    return 0;

}

int pgcdi(int a,int b){
    int q,r;
    while(b !=0){
        r=a%b;
        a=b;
        b=r;
    }

    return b;

}

int pgcdr(int a,int b){
    int r=a%b;
    int q=b;
    int p=r;
    int pgcd;
    if(r != 0){
        pgcd = pgcdr(q,r);
    }
    else
    {
        pgcd=b;
    }
    return pgcd;
}

