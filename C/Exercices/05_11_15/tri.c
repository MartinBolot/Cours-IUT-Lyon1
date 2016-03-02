#include <stdlib.h>
#include <stdio.h> /**/
#include <ctype.h> /*pour les operation sur les str*/
#include <time.h> /*pour le srand*/

#define taillemax 4000

void tri_bulle(int v[],int taille);
void tri_minimum(int v[],int taille);

void gen_jd1(int v[],int taille);
void gen_jd2(int v[],int taille);
void gen_jd3(int v[],int taille);

int main(){
    int i=0,ok,nbchoix,choix,n;
    char rep,tri;

    do{
        printf("taille du vecteur ? (n<%d) : ",taillemax);
        ok = scanf("%d",&n);
        while(getchar()!='\n');
    }while(!ok || n>taillemax);

    /*methode statique*/
    //int v[taillemax];
    /*methode dynamique*/
    int* v = malloc(n*sizeof(int));


    choix=0;
    nbchoix=3;


    do{

        do{
            printf("1. Generation d'un jeu de donnees entieres en croissant\n");
            printf("2. Generation d'un jeu de donnees entieres en decroissant\n");
            printf("3. Generation d'un jeu de donnees entieres aleatoires\n");
            printf("Votre choix : ");
            ok=scanf("%d",&choix);
            while(getchar()!='\n');
        }while (!ok || ok>nbchoix || ok<0);

        switch(choix){
            case 1:
                gen_jd1(v,n);
                break;
            case 2:
                gen_jd2(v,n);
                break;
            case 3:
                gen_jd3(v,n);
                break;
            default:
                gen_jd1(v,n);
        }

        printf("vecteur genere : \n");
        for (i=0;i<n;i++) (i==n-1) ? printf("%d \n",v[i]) : printf("%d,",v[i]);

        do{
            printf("b. methode bulle \n");
            printf("m. methode minimum \n");
            printf("Votre choix : ");
            ok = scanf("%c",&tri);
            while(getchar()!='\n');
        }while (!ok || (tolower(tri)!='b' && tolower(tri)!='m'));

        switch(tri){
            case 'b':
                tri_bulle(v,n);
                break;
            case 'm':
                tri_minimum(v,n);
                break;
            default:
                printf("pas de choix");
        }

        printf("vecteur trie : \n");
        for (i=0;i<n;i++) (i==n-1) ? printf("%d\n",v[i]) : printf("%d,",v[i]);

        printf("Voulez-vous recommencer (o/n) : ");
        scanf("%c",&rep);
        while(getchar()!='\n');
    }while(tolower(rep)!='n');

    /*pour la methode dynamique*/
    free(v);

    return 0;
}


void gen_jd1(int v[],int taille){
    int i;

    for (i=0;i<taille;i++) v[i]=i;
}
void gen_jd2(int v[],int taille){
    int i;

    for (i=0;i<taille;i++) v[i]=taille-i-1;
}
void gen_jd3(int v[],int taille){
    int i;

    srand(time(NULL));

    for (i=0;i<taille;i++) v[i]=rand()-rand();
}

void tri_bulle(int v[],int taille){
    int i,j,temp;

    i=taille-1;

    while(i>=0){
        j=1;
        while(j<=i){
            if(v[j]<v[j-1]){
                temp=v[j];
                v[j]=v[j-1];
                v[j-1]=temp;
            }
            j++;
        }
        i--;
    }
}

void tri_minimum(int v[],int taille){
    int i,j,ipp,petit;

    i=0;
    while(i<taille-1){
        ipp=i;
        petit=v[ipp];
        j=i+1;
        while(j<taille){
            if(v[j]<petit){
                ipp=j;
                petit=v[ipp];
            }
            j++;
        }
        v[ipp]=v[i];
        v[i]=petit;
        i++;
    }

}


