#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ligne_commande.h"

int main(){
	char** saisie;					/* recuperation de la commande saisie */
	pid_t pid;							/* stockage du pid pour le fork */
	int etat;								/* variable de retour pour le fork */
	int commandToExecute;		/* variable de test pour le retour de l'exec */

	do{
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
		  perror("Erreur à l'appel de fork\n");
		  exit(1);
		}

		/* si on est dans le processus fils */
		if(pid==0){
				/* on lance une commande a partir du processus fils */
			 commandToExecute = execvp(saisie[0],saisie);
			 if(commandToExecute==-1){
				 printf("la commande nexiste pas \n");fflush(stdout);
				 return 1;
			 }
		}else{ waitpid(-1,&etat,0); }
		
	}while(strcmp(saisie[0],"exit")!=0);

	return 0;

}
