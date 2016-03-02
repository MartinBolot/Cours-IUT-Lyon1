#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double fibo(int n);

int main(){
    int ok;
    int n;  /*pour accueillir la borne supp*/
    int i=0; /*pour l'iteration*/
    char rep;

    do{
        do{
            printf("Entrer la borne superieure entre 0 et 1000 : ");
            ok=scanf("%d",&n);
            while(getchar()!='\n');
        }while(!ok || n<0 || n>1000);

        for(i=0;i<=n;i++){
            printf("fibo(n) = %f \n",fibo(i));
        }

        printf("Recommencer (o/n) ?");
        scanf("%c",&rep);
        while(getchar()!='\n');
    }while(tolower(rep)!='n');
}

double fibo(int n){
    int i=0;
    double fn,fn1,fn2;

    fn=1;
    fn1=fn;
    fn2=fn;

    for(i=2;i<=n;i++){
        fn = fn1+fn2;
        fn2=fn1;
        fn1=fn;
    }

    return fn;
}
