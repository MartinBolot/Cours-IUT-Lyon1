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
	char** saisie=NULL;		/* recuperation de la commande saisie */
	pid_t pid,bg,pipePid;	/* stockage du pid pour le fork */
	int etat,status;	/* variable de retour pour le fork */
	int commandToExecute;	/* variable de test pour le retour de l'exec */
	char* param;	/* stockage du parametre passé pour export */
	char variable[MAX];		/* stockage du nom de la variable d'env passée pour export */
	int cpt=0;		/* compteur pour récupérer la partie avant le "=" dans le parametre */
	char* p;		/* pointeur pour parcourir la chaine passée en argument d'export */
	int i = 0;	/* variable d iteration */

	/* pour la gestion des pipes */
	int fd[2];	/* descripteur de fichier pour le pipe */
	int indicePipe = 0;	/* indice du symbole "|" dans la commande*/
	char copiePipe[MAX][MAX];	/* copie des arguments */
	char *copieDebutPipe;	/* copie de la chaine avant le "|" */
	char *copieFinPipe;		/* copie de la chaine apres le "|" */


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

		/* on teste s'il y a un pipe dans la commande */
		i = 0;
		indicePipe = 0;
		while(saisie[i]){
			if(strcmp(saisie[i],"|") == 0){
				if(i != 0){
					indicePipe = i;
				}
			}
			i++;
		}
		/* s il y a un pipe */
		if(indicePipe){
				pipe(fd);
				for(i = 0; i < indicePipe; i++){
					strcpy(copiePipe[i],saisie[i]);
				}
				copieDebutPipe = copiePipe[0];
				copieFinPipe = saisie[indicePipe+1];
		}

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
							for(i=0;i<MAX;i++){variable[i]='\0';}
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
				 /* si la commande commence par tf, on prend le deuxieme mot */
				 if(strcmp(saisie[0],"tf")==0){
		 				bg = fork();
		 				if(bg == 0){
		 					if(execvp(saisie[1],saisie+1) == -1){
		 						printf("la commande nexiste pas \n");fflush(stdout);
		 						exit(1);
		 					}
		 				}else{
		 					waitpid(bg,&status,0);
		 					printf("Fin du programme %d (%s)\n",getpid(),saisie[1]);
							exit(0);
		 				}
				 }else{
					 /* s'il y a un pipe */
					 if(indicePipe){
						 close(fd[0]);
						 dup2(fd[1],1);
						 commandToExecute = execvp(copiePipe[0],&copieDebutPipe);
					 }else{
						 /* on lance une commande a partir du processus fils */
						 commandToExecute = execvp(saisie[0],saisie);
					 }
				 }

				 if(commandToExecute==-1){
					 printf("%s : ", saisie[0]);fflush(stdout);
					 printf("la commande nexiste pas \n");fflush(stdout);
					 printf("error on command '%s' - %s \n",saisie[0],strerror(errno));fflush(stdout);
					 return 1;
				 }
			}
		}else{
			if(strcmp(saisie[0],"tf")!=0){
				/* s'il y a un pipe */
				if(indicePipe){
					pipePid = fork();
					if(pipePid == 0){
						close(fd[1]);
						dup2(fd[0],0);
						if(execvp(saisie[indicePipe+1],&copieFinPipe) == -1){
							 printf("%s : ", saisie[indicePipe+1]);fflush(stdout);
							 printf("la commande nexiste pas \n");fflush(stdout);
							 printf("error on command '%s' - %s \n",saisie[indicePipe+1],strerror(errno));fflush(stdout);
							 return 1;
						}
					}else{ waitpid(-1,&etat,0); }
				}
				waitpid(-1,&etat,0);
			}
		}

	}while(strcmp(saisie[0],"exit")!=0);

	return 0;

}
