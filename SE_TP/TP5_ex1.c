#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define HIGH 9
#define LOW 0

int main(int argc,char* argv[]){
	int etat;
	pid_t fils1,fils2,fils3;
	int tubeFd[2];
	char readbuffer[2];
	int cpt1 = 0;
	int average = 0;
	int higher = 0;
	int lower = 0;

	pipe(tubeFd);

	/* fork du premier fils */
	fils1 = fork();
	/* si on se trouve dans le premier fils */
	if(fils1 == 0){
			/* fork du second fils */
			fils2 = fork();
			/* si on se trouve dans le second fils */
			if(fils2 == 0){
					/* fork du troisieme fils */
					fils3 = fork();
					/* si on se trouve dans le troisieme fils */
					if(fils3 == 0){
						
						waitpid(0,&etat,0);
						
						close(tubeFd[0]);
						dup2(tubeFd[1],1);
						close(tubeFd[1]);
						
						execvp("./calculateur3",argv);
						
						return 0;
						
					/* si le troisieme fork a échoué */
					}else if(fils3 == -1){
						printf("erreur fork fils 3 \n");
						return 1;
					}
					/* si on se trouve dans le second fils (parent) */
					else{
						
						waitpid(0,&etat,0);
						
						close(tubeFd[0]);
						dup2(tubeFd[1],1);
						close(tubeFd[1]);
						
						execvp("./calculateur2",argv);
						
						return 0;
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
				dup2(tubeFd[1],1);
				close(tubeFd[1]);
				
				execvp("./calculateur1",argv);
				
				return 0;
			}

			return 0;

	/* si le premier fork a échoué */
	}else if(fils1 == -1){
		printf("erreur fork fils 1 \n");
		return 1;
	/* si on est dans le parent, on attend la valeur a recuperer */
	}else{
		
		printf("Debut des calculs \n");
		
		close(tubeFd[1]);
		
		cpt1 = 1;
		average = 0;
		higher = LOW;
		lower = HIGH;
		while(read(tubeFd[0], readbuffer, sizeof(readbuffer))){
			// on calcule la moyenne et met à jour higher et lower
			if(atoi(readbuffer) > higher){
				higher = atoi(readbuffer);
			}
			if(atoi(readbuffer) < lower){
				lower = atoi(readbuffer);
			}
			
			average += atoi(readbuffer);
			
			// quand on a sorti 10 chiffres
			if(++cpt1%10 == 0){
				printf("Higher : %d ", higher);
				printf("Lower : %d ", lower);
				printf("Average : %d \n", average/cpt1);
				cpt1 = 0;
				average = 0;
				higher = LOW;
				lower = HIGH;
			}
			/* a décommenter si on veut afficher les output */
			//printf("Received number : %s \n", readbuffer);
		}
		
		waitpid(0,&etat,0);
	}
	
	return 0;
}
