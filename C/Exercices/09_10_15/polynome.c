#include <stdlib.h>
#include <ctype.h>
#include <math.h>


void racines_polynome_yoloswag(double a, double b, double c, int *nbracine, double *x1, double *x2);

int main(){

    int ok,nbracine=0;
    char rep;
    double a,b,c,x1,x2;

    do{


        printf("Entrer les coefficients a,b et c du polynome ax2+bx+c :\n");
        do{
            printf("Entrer a :");
            ok = scanf("%lg",&a);
            while(getchar()!='\n');
        }while(!ok);
        do{
            printf("Entrer b :");
            ok = scanf("%lg",&b);
            while(getchar()!='\n');
        }while(!ok);
        do{
            printf("Entrer c :");
            ok = scanf("%lg",&c);
            while(getchar()!='\n');
        }while(!ok);

        racines_polynome_yoloswag(a,b,c,&nbracine,&x1,&x2);

        switch(nbracine){
            case -2:
                printf("Le polynome est constant et n'a pas de racine");
                break;
            case -1:
                printf("Le polynome a une infinite de racines");
                break;
            case 0:
                printf("Le polynome n'a pas de racine dans R");
                break;
            case 1:
                printf("Le polynome a une racine double; racine = %f",x1);
                break;
            case 2:
                printf("Le polynome a deux racines double; racine1 = %f racine2 = %f",x1,x2);
                break;
            default:
                printf("Vous avez le swag, yolo");

        }
        printf("\n");

        printf("Recommencer (o/n) ?");
        scanf("%c",&rep);
    }while(tolower(rep)!='n');


    return 0;
}


void racines_polynome_yoloswag(double a, double b, double c, int *nbracine, double *x1, double *x2){
    double delta=0;

    delta=pow(b,2.0)-(4.0*a*c);

    if(a==0 && b==0 && c==0){
        *nbracine=-1;
    }else if(a==0 && b==0){
        *nbracine=-2;
    }else{
        if(delta<0){
            *nbracine=0;
        }else if(delta==0){
            *nbracine=1;
            *x1 = (-b+sqrt(delta))/(2*a);
        }else if(delta>0){
            *nbracine=2;
            *x1 = (-b+sqrt(delta))/(2*a);
            *x2 = (-b-sqrt(delta))/(2*a);
        }
    }
}
