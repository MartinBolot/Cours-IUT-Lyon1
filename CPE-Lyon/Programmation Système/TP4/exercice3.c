#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define N 4

/*
 * ssize_t write(int fd, const void *buf, size_t count);
 * ssize_t read(int fd, void *buf, size_t count);
 */
int main() {
	int pipeNombresPairs[2], pipeNombreImpairs[2];
	int pidFiltrePair, pidFiltreImpair;
	int nombres[N];;
	int i = 0, readInt = 0, writeInt = 0;
	int status;
	
	
	pipe(pipeNombresPairs);
	pipe(pipeNombreImpairs);
	
	pidFiltrePair = fork();
	
	// fitre pair
	if(pidFiltrePair == 0) {
		// on ferme ce dont on a pas besoin
		close(pipeNombreImpairs[0]);
		close(pipeNombreImpairs[1]);
		
		// on ferme l'entrée de pipeNombresPairs pour lire la sortie + on ferme la sortie
		close(pipeNombresPairs[1]);
		printf("read %d\n", read(pipeNombresPairs[0], &readInt, sizeof(int)));
		close(pipeNombresPairs[0]);
		printf("%d \n", readInt);
		
		return 0;
	}
	else {
		
		pidFiltreImpair = fork();
		
		// filtre impair
		if(pidFiltreImpair == 0) {
			// on ferme ce dont on a pas besoin
			close(pipeNombreImpairs[0]);
			close(pipeNombreImpairs[1]);
			close(pipeNombresPairs[0]);
			close(pipeNombresPairs[1]);
		}
		
		// generateur
		else {
			// on ferme ce dont on a pas besoin
			close(pipeNombreImpairs[0]);
			close(pipeNombreImpairs[1]);
			
			close(pipeNombresPairs[0]);
			for(i = 0; i < N; i++) {
				nombres[i] = i;
				
				// si nombre pair on dépose dans tube pair
				//if(i%2 == 0) {
				if(i == 2) {
					// on ferme la sortie de pipeNombresPairs pour écrire dans l'entrée + on ferme l'entrée
					writeInt = i;
					printf("%d\n", writeInt);
					printf("write %d\n", write(pipeNombresPairs[1], &writeInt, sizeof(int)));
				}
			}
			close(pipeNombresPairs[1]);
			
			wait(&status);
		}
	}
	
	
	return 0;
}