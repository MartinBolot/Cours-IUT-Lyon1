#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "./dijkstra.h"

#define BUFFER_SIZE 10
#define MAX_LOOP 20
#define CLE_CONSO 123
#define CLE_PROD 124


struct ProdCons{
	int buffer[BUFFER_SIZE];
	int posLect;
	int posEcr;
	sem_t semLecture;
	sem_t semEcriture;
};

// variable globale
int compteur = 0;

struct ProdCons prodCons;

void *consommer(void *arg) {
	sem_wait(&(prodCons.semLecture));
	int i = 0;
	for(i = 0; i < BUFFER_SIZE; i++) {
		printf("%d\n", prodCons.buffer[i]);
	}
	sem_post(&(prodCons.semLecture));
}

void *produire(void *arg) {
	sem_wait(&(prodCons.semEcriture));
	int i = 0;
	for(i = 0; i < BUFFER_SIZE; i++) {
		compteur++;
		prodCons.buffer[i] = compteur;
	}
	sem_post(&(prodCons.semLecture));
}

int main() {
	int i = 0;
	pthread_t producteur, consommateur;
	void *retour;
	
	for(i = 0; i < BUFFER_SIZE; i++) {
		prodCons.buffer[i] = 0;
	}
	
	prodCons.semLecture = (sem_t) sem_create(CLE_CONSO, 0);
	prodCons.semEcriture = (sem_t) sem_create(CLE_CONSO, 0);
	
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