#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ligne_commande.h"

#define MAX 50

int main(){
	char** saisie=NULL;				/* recuperation de la commande saisie */
	pid_t pid;						/* stockage du pid pour le fork */
	int etat;							/* variable de retour pour le fork */
	int commandToExecute;	/* variable de test pour le retour de l'exec */
	char* param;					/* stockage du parametre passé pour export */
	char variable[MAX];		/* stockage du nom de la variable d'env passée pour export */
	int cpt=0;						/* compteur pour récupérer la partie avant le "=" dans le parametre */
	char* p;					/* pointeur pour parcourir la chaine passée en argument d'export */

	do{
		/* on affiche l'invite de base si INVITE n'existe pas, la personnalisée sinon */
		getenv("INVITE")==NULL ? printf("Invite : ") : printf("%s : ",getenv("INVITE"));fflush(stdout);

		/* récupération de la commande */
		do {
			saisie = lis_ligne();
			if(saisie==NULL){ exit(0); }	/* si rien n'est entré, on quitte */
		} while(ligne_vide(saisie));

		/* si l'utilisateur a rentré exit, on quitte */
		if(strcmp(saisie[0],"exit")==0){ exit(0); }

		/* fork avec gestion d'erreur */
		pid = fork();
		if (pid==-1){
		  perror("Erreur a l'appel de fork\n");
		  exit(1);
		}

		/* si on est dans le processus fils */
		if(pid==0){
			/* s'il s'agit de la commande export, on traite "en interne" */
			 if(strcmp(saisie[0],"export")==0){
				 /* si pas de parametre, on ne fait rien*/
					if(saisie[1]==NULL){
						printf("erreur parametre manquant \n");fflush(stdout);
 					 	return 1;
					}else{
						/* on récupère l'argument de export passée */
						p = saisie[1];
						while(*p!='=' && *p!='\0'){ p++;cpt++; }
						if(*p=='='){

							/* on recupere la variable */
							for(int i=0;i<MAX;i++){variable[i]='\0';}
							strncpy(variable,saisie[1],cpt);

							/* on recupere le paramètre */
							param = separe_egal(saisie[1]);

							/* on met à jour la variable d'environnement demandée */
							setenv(variable,param,1);

						}else{
							printf("erreur manque le contenu de la variable \n");fflush(stdout);
	 					 	return 1;
						}

					}
			 }else{
				 /* on lance une commande a partir du processus fils */
	 			 commandToExecute = execvp(saisie[0],saisie);
	 			 if(commandToExecute==-1){
	 				 printf("la commande nexiste pas \n");fflush(stdout);
					 return 1;
	 			 }
			}
		}else{ waitpid(-1,&etat,0); }

	}while(strcmp(saisie[0],"exit")!=0);

	return 0;

}
