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
	int size = (SIZE_BUFFER * sizeof(char)) + (2 * sizeof(int));
	//semaphores
	/*
	int semid_conso;
	int semid_prod;
	int mutex_conso;
	int mutex_prod;
	*/
	char *mem;
	int flag = 0;
	
	// creation mémoire partagée 1
	shmid = shmget((key_t)CLE_VALEURS, size, IPC_CREAT|IPC_EXCL|0666);
	
	if(shmid == -1) {
		shmid = shmget((key_t)CLE_VALEURS, size, 0666);
		if(shmid == -1) {
			perror("Echec de shmget");
			exit(1);
		}
		// le segement existe déjà, on le supprime puis recrée
		else {
			if(shmctl(shmid, IPC_RMID, NULL) == -1) {
				perror("Erreur lors de la suppression de la memoire partagee precedante");
			}
			else {
				shmid = shmget((key_t)CLE_VALEURS, size, IPC_CREAT|IPC_EXCL|0666);
				
				if(shmid == -1) {
					perror("Echec de la re-creation");
					exit(1);
				}
			}
		}
		// on initialise
		mem = shmat(shmid, 0, flag);
		
		if(mem == (char*) -1) {
			perror("attachement impossible");
			exit(1);
		}
		else {
			mem[SIZE_BUFFER] = 0;
			mem[SIZE_BUFFER + 1] = 0;
		}
	}
	printf("memoire partagee: cle: %d, ID: %d \n", CLE_VALEURS, shmid);
	
	//creation sémaphore 1
	sem_create(CLE_CONSO, 0);
	
	//creation sémaphore 2
	sem_create(CLE_PROD, 5);
	
	//creation sémaphore pointeurs
	sem_create(CLE_MUTEX_CONSO, 1);
	
	//creation sémaphore pointeurs
	sem_create(CLE_MUTEX_PROD, 1);
	
	/*
	semid_conso = sem_create(CLE_CONSO, 0);
	semid_prod = sem_create(CLE_PROD, 5);
	mutex_conso = sem_create(CLE_MUTEX_CONSO, 1);
	mutex_prod = sem_create(CLE_MUTEX_PROD, 1);
	printf("semaphore: cle: %d, ID: %d \n", CLE_CONSO, semid_conso);
	printf("semaphore: cle: %d, ID: %d \n", CLE_PROD, semid_prod);
	printf("semaphore: cle: %d, ID: %d \n", CLE_MUTEX_CONSO, mutex_conso);
	printf("semaphore: cle: %d, ID: %d \n", CLE_MUTEX_PROD, mutex_prod);
	*/
	
	return 0;
}