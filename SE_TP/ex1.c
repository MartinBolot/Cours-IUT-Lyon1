#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char* argv[]){
	int etat;
	pid_t fils1,fils2,fils3;
	int tubeFd[2];
	char string[] = "Hello, world!\n";
	//char readbuffer[80];
	int *readbuffer;
	int nbytes;

	pipe(tubeFd);

	/* fork du premier fils */
	fils1 = fork();
	/* si on se trouve dans le premier fils */
	if(fils1 == 0){
			printf("fils 1 \n");

			/* fork du second fils */
			fils2 = fork();
			/* si on se trouve dans le second fils */
			if(fils2 == 0){
					printf("fils 2 \n");

					/* fork du troisieme fils */
					fils3 = fork();
					/* si on se trouve dans le troisieme fils */
					if(fils3 == 0){
						printf("fils 3 \n");
					/* si le troisieme fork a échoué */
					}else if(fils3 == -1){
						printf("erreur fork fils 3 \n");
						return 1;
					}
					/* si on se trouve dans le second fils (parent) */
					else{
						waitpid(0,&etat,0);
					}

					return 0;
			/* si le second fork a échoué */
			}else if (fils2 == -1){
				printf("erreur fork fils 2 \n");
				return 1;
			}
			/* si on se trouve dans le premier fils (parent) */
			else{
				waitpid(0,&etat,0);

				close(tubeFd[0]);
				/* Send "string" through the output side of pipe */
	      //write(tubeFd[1], string, (strlen(string)+1));
				dup2(tubeFd[1],1);
				close(tubeFd[1]);
				execvp("./test",NULL);
			}

			return 0;

	/* si le premier fork a échoué */
	}else if(fils1 == -1){
		printf("erreur fork fils 1 \n");
		return 1;
	/* si on est dans le parent, on attend la valeur a recuperer */
	}else{
		close(tubeFd[1]);
		/* Read in a string from the pipe */

		//nbytes = read(tubeFd[0], readbuffer, sizeof(readbuffer));
		//printf("Received string: %s \n", readbuffer);

		nbytes = read(tubeFd[0], readbuffer, sizeof(int));
		printf("Received number : %d \n", *readbuffer);

		waitpid(0,&etat,0);
	}

	return 0;
}
