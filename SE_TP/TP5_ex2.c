#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc,char* argv[]){
	int etat;
	pid_t fils1,keyTestProcess;
	int gene2pere[2];
	int pere2decrypt[2];
	int decrypt2pere[2];
	char readBuffer[50];
	char readBuffer2[50];

	pipe(gene2pere);
	pipe(pere2decrypt);
	pipe(decrypt2pere);

	/* fork du premier fils */
	fils1 = fork();
	/* si on se trouve dans le premier fils */
	if(fils1 == 0){
			// on paramètre la redirection puis on execute le générateur
			close(gene2pere[0]);
			dup2(gene2pere[1],1);
			close(gene2pere[1]);
			execvp("./generateur",argv);

			return 0;

	/* si le premier fork a échoué */
	}else if(fils1 == -1){
		printf("erreur fork fils 1 \n");
		return 1;
	/* ici on est dans le pere donc on traite les cles generees*/
	}else{

		printf("Recherche \n");

		close(gene2pere[1]);
		dup2(gene2pere[0],0);

		while(1){
			// on lit puis affiche la clé
			scanf("%s",readBuffer); // a améliorer car on perd certaines clés
			printf("Received key : %s \n",readBuffer);

			// a chaque lecture de clé on crée un processus fils qui va la tester
			keyTestProcess = fork();
			if(keyTestProcess == 0){
				// on teste la clé avec le descripteur
				// avant de la renvoyer au processus père
				close(pere2decrypt[0]);
				close(pere2decrypt[1]);
				close(pere2decrypt[1]);
				dup2(pere2decrypt[1],0);
				dup2(decrypt2pere[0],1);
				execvp("./decrypteur",argv);

				return 0;
			}else if(keyTestProcess == -1){
				printf("Erreur dans le sous-fork");
				return 1;
			}else{
				close(pere2decrypt[1]);
				close(decrypt2pere[1]);
				write(pere2decrypt[0],readBuffer,sizeof(readBuffer));
				read(gene2pere[0],readBuffer2,sizeof(readBuffer2));

				// ici il aurait fallut comparer la chaine récupérée après décryptage
				// avec la chaine "bravo" - juste les 5 premiers caracteres donc
				// malheureusement impossible de récupérer cette partie de la chaîne
				/*if(strcmp(compare,"bravo") == 0){
					exit(0);
				}*/

				kill(keyTestProcess,SIGUSR1);
				waitpid(keyTestProcess,&etat,0);
			}

		}

		waitpid(0,&etat,0);

	}

	return 0;
}
