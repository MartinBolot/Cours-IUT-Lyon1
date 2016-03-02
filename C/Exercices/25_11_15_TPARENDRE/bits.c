/*
    auteurs : Martin BOLOT et Marion CRAIPEAU
    Groupe - ASPE
    Date : 26/11/2015
*/
#include <stdio.h>
#include <limits.h>  /* pour INT_MIN sur certains compilateurs C */
#include <ctype.h>

#define TAILLEINT 8*sizeof(int) /*on définit la taille de représentation d'un int*/

/* affiche n bit par bit */
void aff_bits( int n );

/* affiche n bit par bit */
int inverse( unsigned x, unsigned p, unsigned n );

/*effectue une rotation vers la droite de n sur b bits*/
int rot_droite( unsigned n, unsigned b );


int main(){     /*fonction principale appelante*/
    int ok;
    int n;  /*nombre de bits pour la fonction inversion*/
    int p;  /*position a partir de laquelle inverser pour la fonction inversion*/
    int x;  /*nombre en entree sur lequel on va travailler*/
    int b;  /*nombre de bits pour la permutation vers la droite*/
    int i;  /*variable utilisee pour les boucles*/
    char rep;   /*charactere de la reponse pour "voulez vous recommencer"*/

    do{
        printf(
            "\tMANIPULATION DE BITS\n"
            "\t--------------------\n"
        );

        /*On recuperer le nombre sur lequel on va travailler*/
        do{
            printf("Donnez un entier quelconque: ");
            ok=scanf("%d",&x);
            while(getchar()!='\n');
        }
        while(!ok);

        /*On affiche la representation binaire du nombre*/
        printf("Voici sa representation en binaire : \n");
        aff_bits(x);
        printf("\n");

        /*inversion des bits*/
        printf("On va inverser n bits de ce nombre a compter du p eme: \n");

        /*on recupere la position, positive et inferieure a la taille max d'un int*/
        do{
            printf("Donner p ( > 0 et <= %2d ) : ", TAILLEINT);
            ok=scanf("%d",&p);
            while(getchar()!='\n');
        }while(!ok || p<=0 || p>TAILLEINT);

        /*On recupere le nombre entre 0 et p de bits a inverser*/
        do{
            printf("Donner n ( > 0 et <= %2d ) : ",p);
            ok=scanf("%d",&n);
            while(getchar()!='\n');
        }while(!ok || n<=0 || n>p);

        /*On affiche le nouveau nombre avec bits inverses*/
        aff_bits(inverse(x,p,n));
        /*puis on souligne les bits concernes grace a une boucle*/
        for(i=TAILLEINT-1; i>=0; i--){
            if(i<=p-1 && i>p-n){
                printf("--");
            }
            else if(i==p-n){
                printf("-");
            }
            else{
                printf("  ");
            }
        }

        printf("\n\nSur le nombre \"%d\" de representation binaire\n", x);
        aff_bits(x);
        printf("\nOn va effectuer une permutation circulaire vers la DROITE de b bits.\n");
        /*on recupere la taille du decalage en bits*/
        do{
            printf("Donnez b ( >0 ): ");
            ok=scanf("%d",&b);
            while(getchar()!='\n');
        }
        while(!ok || b<=0);

        /*on affiche la nouvelle suite de bits decalee*/
        aff_bits(rot_droite(x,b));

        /*on demande a l'utilisateur s'il souhaite recommencer*/
        printf("Recommencer (o/n) ? : ");
        scanf("%c",&rep);
        while( getchar()!='\n');
    }while(tolower(rep) != 'n');

    return 0;
}

/* affiche n bit par bit */
void aff_bits( int n ){
    unsigned masque = INT_MIN; /*masque de la taille du plus petit int*/
    int i;    /*variable de boucle*/

    /*pour chaque bit on compare au masque et on affiche 0 ou 1 en fonction du resultat*/
    /*puis on decale le masque d'un bit vers la droite*/
    for( i = 0; i < TAILLEINT; i++ ){
        if ((n&masque)==0){
            printf("0 ");
        }
        else{
            printf("1 ");
        }
        masque >>= 1;
    }
  printf("\n");
}

/*inverse les bits à partir du bit numero p sur n bits*/
int inverse( unsigned x, unsigned p, unsigned n ){
    if(n == TAILLEINT){
        return( ~x );
    }else {
        return( x ^ ( ~ ( -1 << n ) << (p - n) ) );
    }
}

/*on effectue une rotation vers la droite de n sur b bits*/
int rot_droite( unsigned n, unsigned b ){
    unsigned r,s;
    int x,y,modulo; /*x pour stocker b en int, y taille d'un int, modulo pour gerer les nombres superieurs a la taille de notre nombre*/

    x = (int)b;
    y = TAILLEINT;
    modulo = (x % y);
    b = (unsigned)modulo;
    if( b > 0 ){
        s = n >> b;
        r = n << ( TAILLEINT - b );
        return( s | r );
    }else{
        return n;
    }
}
