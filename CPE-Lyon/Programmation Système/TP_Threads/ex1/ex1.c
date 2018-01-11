#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// variable globale
int compteur = 0;

void *consommer(void *arg) {
	while(compteur < 40) {
		compteur++;
		sched_yield();
	};
}

void *produire(void *arg) {
	while(compteur < 40) {
		if(compteur < 39) {
			printf("%d - ", compteur);
		}
		else {
			printf("%d\n", compteur);
		}
		sched_yield();
	};
}

int main() {
	
	pthread_t producteur, consommateur;
	void *retour;
	
	if(pthread_create(&producteur, NULL, produire, NULL) != 0){
		perror("erreur create producteur");
		exit(-1);
	}
	if(pthread_create(&consommateur, NULL, consommer, NULL) != 0){
		perror("erreur create consommateur");
		exit(-1);
	}
	
	pthread_join(producteur, &retour);
	pthread_join(consommateur, &retour);
	
	return 0;
}