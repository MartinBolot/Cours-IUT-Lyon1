#include <stdio.h>
#include <ctype.h>
#define NMAX 4

void lectmat(int v[][NMAX],int n);
void affmat(int v[][NMAX],int n);
void symmat(int v[][NMAX],int n);
void addmat(int a[][NMAX],int b[][NMAX],int n);
void multmat(int a[][NMAX],int b[][NMAX],int n);
void pause();


int main(){
    int ok,c,n;
    int a[NMAX][NMAX],b[NMAX][NMAX];
    char rep;

    do{
        do{
            printf("1...lecture des matrices a et b \n");
            printf("2...symetrie des matrices a et b \n");
            printf("3...addition des matrices a et b \n");
            printf("4...multiplication de la matrice a par b \n");
            printf("5...multiplication de la matrice b par a \n");
            printf("6...sortie \n");
            printf( "\nVotre choix");
            ok = scanf( "%d", &c );
            while( getchar( ) != '\n' );  /* ou fgets(vb,80,stdin)  avec  char vb[81];  */
        }while(!ok || c<1 || c>6);

        do{
            printf("Entrer la dimension des matrices carrees (<=4) : ");
            ok = scanf( "%d", &n );
            while( getchar( ) != '\n' );  /* ou fgets(vb,80,stdin)  avec  char vb[81];  */
        }while(!ok || n<0 || n>4);

        switch(c){
            case 1:
                printf("matrice a : \n");
                lectmat(a,n);
                printf("matrice b : \n");
                lectmat(b,n);
                affmat(a,n);
                affmat(b,n);
                break;
            case 2:
                symmat(v,n);
                affmat(v,n);
                break;
            case 3:
                addmat(a,b,n);
                break;
            case 4:
                multmat(a,b,n);
                break;
            case 5:
                multmat(b,a,n);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Erreur");
        }

        printf( "Voulez-vous recommencer (o/n): " );
        scanf( "%c", &rep );
        while( getchar( ) != '\n' );  /* ou fgets(vb,80,stdin)  avec  char vb[81];  */
    }while( tolower( rep ) != 'n' );

    return 0;
}

void lectmat(int v[][NMAX],int n){
    int i,j,ok;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            do{
                printf("Entrer valeur v[%d][%d] : ",i,j);
                ok=scanf("%d",&v[i][j]);
                while(getchar()!='\n');
            }while(!ok);
        }
    }
}

void affmat(int v[][NMAX],int n){
    int i,j;

    printf("matrice : \n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            /*printf("v[%d][%d] = %d \n",i,j,v[i][j]);*/
            printf("%d \t",v[i][j]);
        }
        printf("\n");
    }
}

void symmat(int v[][NMAX],int n){
    int i,j,temp;

/* marche aussi */
/*
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j!=i && j<i){
                temp=v[i][j];
                v[i][j]=v[j][i];
                v[j][i]=temp;
            }
        }
    }
*/
/*methode jean*/
    for(i=0;i<n;i++){
        for(j=1;j<n;j++){
            if(j!=i){
                temp=v[i][j];
                v[i][j]=v[j][i];
                v[j][i]=temp;
            }
        }
    }
}


void addmat(int a[][NMAX],int b[][NMAX],int n){
    int c[NMAX][NMAX];
    int i,j;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }

    affmat(c,n);
}

void multmat(int a[][NMAX],int b[][NMAX],int n){
    int c[NMAX][NMAX]={0};
    int i,j,k;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                c[i][k] += a[i][j]*b[j][k];
            }
        }
    }

    affmat(c,n);
}
