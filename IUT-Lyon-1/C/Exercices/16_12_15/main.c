#include <stdio.h>   /* pour scanf, printf,FILE, NULL ... */
#include <stdlib.h>  /* pour les fonctions exit, srand et rand */
#define NBSEP 22


int main(int argc, char *argv[]){

    int i,cpt,nbligne,nbmot,nbcar;
    char c;
    char getS[81];
    char liste_sep[NBSEP]={' ','\n','[',']','|','.',',',
                            '<',':',';','(',')','?','!',
                            '\t','/','\\','#','{','}','=','^'};
    FILE *f;


    /*printf("Voici les %d arg(s) passes sur la lig de cmd : \n",argc);
    for(i=0;i<argc;i++){
        printf("%d - %s \n",i+1,argv[i]);
    }*/
    if(argc==2){
        /*comptage ligne*/
        f=fopen(argv[1],"r");
        if(!f){
             printf("Ouverture du fichier d'entree impossible");
             exit(1);
        }else{
            cpt=0;
            while(fgets(getS,80,f)!=NULL) cpt++;
            printf("ligne : %d\n",cpt);
        }
        fclose(f);
        nbligne=cpt;

        /*comptage mots*/
        f=fopen(argv[1],"r");
        if(!f){
             printf("Ouverture du fichier d'entree impossible");
             exit(1);
        }else{
            cpt=0;
            while((c=fgetc(f))!=EOF){
                        //printf("c:%d\n",c);
                for(i=0;i<NBSEP;i++){
                    if(c==liste_sep[i]){
                        cpt++;
                    }
                }
            }
            printf("nbmot : %d\n",cpt);
        }
        fclose(f);
        nbmot=cpt;


        /*comptage carac*/
        f=fopen(argv[1],"r");
        if(!f){
             printf("Ouverture du fichier d'entree impossible");
             exit(1);
        }else{
            cpt=0;
            while(fgetc(f)!=EOF) cpt++;
            printf("nbcar : %d\n",cpt);
        }
        fclose(f);
        nbcar=cpt;
    }else{
        printf("Il faut rentrer un seul nom de fichier");
        exit(2);
    }



    return 0;
}
