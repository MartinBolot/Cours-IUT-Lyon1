#include <stdlib.h>
#include <ctype.h>

#define true 1
#define false 0

typedef int bool;

void pair_impair1(int n, double *sp, double *simp){
    int i;
    double somme=0;

    *sp=0;
    *simp=0;

    for(i=2;i<=n;i+=2){
        *sp+=i;
    }
    for(i=1;i<=n;i++){
        somme+=i;
    }
    *simp=somme-*sp;
}

void pair_impair2(int n, double *sp, double *simp){
    int i=1;

    *sp=0;
    *simp=0;

    while(i<=n){
        if(i%2==0){
            *sp+=i;
        }else{
            *simp+=i;
        }
        i++;
    }
}

void pair_impair3(int n, double *sp, double *simp){
    bool i_est_pair=false;
    int i=1;

    *sp=0;
    *simp=0;

    while(i<=n){
        if(i%2==0){
            i_est_pair=true;
        }else{
            i_est_pair=false;
        }
        switch(i_est_pair){
            case true:
                *sp+=i;
                break;
            case false:
                *simp+=i;
                break;
        }
        i++;
    }
}

void pair_impair4(int n, double *sp, double *simp){
    *sp=0;
    *simp=0;

    if(n%2==0){
        *sp=(n/2.0)*((n/2.0)+1);
        *simp=(n/2.0)*(n/2.0);
    }else{
        *sp=(n/2.0)*(n/2.0);
        *simp=(n/2.0)*((n/2.0)+1);
    }
}

int main(){
    int ok,n;
    double sp;
    double * P_sp;
    double simp;
    double * P_simp;

    P_sp=&sp;
    P_simp=&simp;

    do{
        printf("Entrer un entier >= 0 :");
        ok = scanf("%d",&n);
        while(getchar()!='\n');
    }while(!ok || n<0);

    pair_impair1(n,P_sp,P_simp);
    printf("Solution 1 : n = %d ; sp = %.f ; simp = %.f\n",n,sp,simp);
    pair_impair2(n,P_sp,P_simp);
    printf("Solution 2 : n = %d ; sp = %.f ; simp = %.f\n",n,sp,simp);
    pair_impair3(n,P_sp,P_simp);
    printf("Solution 3 : n = %d ; sp = %.f ; simp = %.f\n",n,sp,simp);
    pair_impair4(n,P_sp,P_simp);
    printf("Solution 4 : n = %d ; sp = %.f ; simp = %.f",n,sp,simp);

    printf("\n");
    return 0;
}
