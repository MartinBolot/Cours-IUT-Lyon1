#include <stdio.h>
#include <ctype.h>

double moyenne1(int n);
double moyenne2(int n);
double moyenne3(int n);


int main()
{
    int n=0;
    char rep;
    int ok;
    do{
        n=0;
        rep='a';
        do{
            printf("Entrer un entier n (n>=1 ) borne de l'ensemble {1,2,3...,n}:\n");
            ok=scanf("%d",&n);
            while(getchar( ) != '\n');
        }while( !ok || n<0 );


        printf("La methode 1 donne une moyenne egale a %.1f\n",moyenne1(n));
        printf("La methode 2 donne une moyenne egale a %.1f\n",moyenne2(n));
        printf("La methode 3 donne une moyenne egale a %.1f\n",moyenne3(n));

        printf("Recommencer?(o/n)\n");
        rep=scanf("%c",&rep);
        while(getchar( ) != '\n');

    }while(tolower(rep) !='n');

    return 0;

}

double moyenne1(int n)
{
    int i=1;
    double moyenne=0;
    while(i<=n)
    {
        moyenne=moyenne+i;
        i++;
    }
    return moyenne/n;
}

double moyenne2(int n)
{
    int i;
    double moyenne=0;
    for(i=1; i<=n ; i++){
        moyenne=moyenne+i;
    }
    return moyenne/n;
}
double moyenne3(int n)
{

    /*
    if(n==1)
       moyenne=1;
    else
        moyenne= moyenne3(n-1)+n;
        */

    return (1+n)/2.0;
}
