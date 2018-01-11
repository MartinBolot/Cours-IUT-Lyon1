#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NB_MAX 10

pthread_mutex_t verrou = PTHREAD_MUTEX_INITIALIZER;

void *compute(void *arg) {
	pthread_mutex_lock(&verrou);
	printf("execution thread %d \n", *((int *)arg)+1);
	pthread_mutex_unlock(&verrou);
}

int main(int argc, char *argv[]) {
	
	int alnumToInt;
	int i;
	int j[NB_MAX];
	void *returnValue;
	pthread_t threads[NB_MAX];
	
	pthread_mutex_lock(&verrou);
	
	// récupération argument
	if(argc > 1) {
		alnumToInt = atoi(argv[1]);
		
		// si argument OK
		if(alnumToInt) {
			printf("%d threads à créer\n", alnumToInt);
			
			// on crée les threads
			for(i = 0; i < alnumToInt; i++) {
				j[i] = i;
				if(pthread_create(&threads[i], NULL, compute, &j[i]) != 0) {
					printf("erreur creation thread %d \n", i);
					exit(1);
				}
			}
			
			printf("Appuyer sur entrée pour lancer les threads \n");
			getchar();
			pthread_mutex_unlock(&verrou);
			
			for(i = 0; i < alnumToInt; i++) {
				pthread_join(threads[i], &returnValue);
			}
		}
		else {
			printf("argument invalide\n");
			exit(1);
		}
	}
	else {
		printf("argument manquant\n");
		exit(1);
	}
	
	return 0;
}