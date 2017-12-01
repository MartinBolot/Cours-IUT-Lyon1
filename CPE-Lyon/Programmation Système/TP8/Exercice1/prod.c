#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>
#include "shared.h"
#include "dijkstra.h"

int main(int argc, char** argv) {
	
	int shmid;
	char charToPut;
	int size = SIZE_BUFFER;
	char *mem;
	int *indexProd;
	int flag = 0;
	int semid_prod;
	int semid_conso;
	int mutex_prod;
	
			
	// on considère le sémaphore de consomation et prod
	semid_prod = sem_create(CLE_PROD, 5);
	semid_conso = sem_create(CLE_CONSO, 0);
	mutex_prod = sem_create(CLE_MUTEX_PROD, 1);
			
	if(argc > 1) {
		charToPut = argv[1][0];
		
		shmid = shmget((key_t) CLE_VALEURS, size, 0666);
		if(shmid == -1) {
			perror("erreur recuperation cle");
			exit(1);
		}
		else {
			if(semid_prod == -1) {
				perror("echec recuperation semaphore prod");
				exit(1);
			}
			else if(semid_conso == -1){
				perror("echec recuperation semaphore conso");
				exit(1);
			}
			else if (mutex_prod == -1) {
				perror("echec recuperation mutex conso");
				exit(1);
			}
			else {
				
				P(semid_prod);
				
				mem = shmat(shmid, 0, flag);
				
				if(mem == (char*) -1) {
					perror("attachement impossible");
					exit(1);
				}
				else {
					
					P(mutex_prod);
					
					// FIXME
					indexProd = mem + (SIZE_BUFFER * sizeof(char));
					mem[*indexProd] = charToPut;
					indexProd[0] = (indexProd[0] + 1) % SIZE_BUFFER;
					
					V(mutex_prod);
				}
				
				V(semid_conso);
			}
		}
	}
	else {
		exit(0);
	}
	
	return 0;
}