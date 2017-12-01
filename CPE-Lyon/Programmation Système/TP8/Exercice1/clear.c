#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include "shared.h"
#include "dijkstra.h"

int main() {
	
	// mémoires partagées
	int shmid;
	int size = (SIZE_BUFFER * sizeof(char)) + (2 * sizeof(char));
	//semaphores
	int semid_conso;
	int semid_prod;
	int semid_pointeurs;
	int mutex_conso;
	int mutex_prod;
	
	// suppression memoire partage 1
	shmid = shmget((key_t)CLE_VALEURS, size, 0666);
	if(shmid == -1) {
		perror("echec recuperation memoire");
		exit(1);
	}
	else if(shmctl(shmid, IPC_RMID, NULL) == -1) {
		perror("Echec de shmctl");
		exit(1);
	}
	else {
		printf("memoire partagee suprimee: cle: %d, ID: %d \n", CLE_VALEURS, shmid);
	}
	
	// suppression sémaphore conso
	semid_conso = sem_create(CLE_CONSO, 0);
	if(semid_conso == -1) {
		perror("echec recuperation semaphore");
		exit(1);
	}
	else {
		sem_delete(semid_conso);
		//printf("semaphore supprimee: cle: %d, ID: %d \n", CLE_CONSO, semid_conso);
	}
	
	// suppression sémaphore prod
	semid_prod = sem_create(CLE_PROD, 0);
	if(semid_prod == -1) {
		perror("echec recuperation semaphore");
		exit(1);
	}
	else {
		sem_delete(semid_prod);
		//printf("semaphore supprimee: cle: %d, ID: %d \n", CLE_PROD, semid_prod);
	}
	
	// suppression mutex conso
	mutex_conso = sem_create(CLE_MUTEX_CONSO, 0);
	if(mutex_conso == -1) {
		perror("echec recuperation semaphore");
		exit(1);
	}
	else {
		sem_delete(mutex_conso);
		//printf("semaphore supprimee: cle: %d, ID: %d \n", CLE_MUTEX_CONSO, mutex_conso);
	}
	
	// suppression mutex prod
	mutex_prod = sem_create(CLE_MUTEX_PROD, 0);
	if(mutex_prod == -1) {
		perror("echec recuperation semaphore");
		exit(1);
	}
	else {
		sem_delete(mutex_prod);
		//printf("semaphore supprimee: cle: %d, ID: %d \n", CLE_MUTEX_PROD, mutex_prod);
	}
	
	return 0;
}