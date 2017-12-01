#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>
#include "shared.h"
#include "dijkstra.h"

int main() {
	
	int shmid;
	int size = SIZE_BUFFER;
	char *mem;
	char *lecture;
	int flag = 0;
	int* indexConso;
	int semid_prod;
	int semid_conso;
	int mutex_conso;
	
		
	// on considère le sémaphore de consomation
	semid_prod = sem_create(CLE_PROD, 5);
	semid_conso = sem_create(CLE_CONSO, 0);
	mutex_conso = sem_create(CLE_MUTEX_CONSO, 1);
	
	shmid = shmget((key_t) CLE_VALEURS, size, 0666);
	if(shmid == -1) {
		perror("erreur recuperation cle");
		exit(1);
	}
	// memoire partagée accessible
	else {
		if(semid_prod == -1) {
			perror("echec recuperation semaphore prod");
			exit(1);
		}
		else if(semid_conso == -1) {
			perror("echec recuperation semaphore conso");
			exit(1);
		}
		else if(mutex_conso == -1) {
			perror("echec recuperation mutex conso");
			exit(1);
		}
		else {
			
			// on vérifie que le buffer n'est pas vide et on prend la semaphore
			lecture = shmat(shmid, 0, flag);
			
			if(lecture == (char*) -1) {
				perror("attachement impossible char");
				exit(1);
			}
			else {
				// detachement
				if(shmdt(lecture) == -1){
					perror("detachement impossible char");
					exit(1);
				}
				
				//prise semaphore
				P(semid_conso);
				
				/* lecture */
				mem = shmat(shmid, 0, flag);
				
				if(mem == (char*) -1) {
					perror("attachement impossible");
					exit(1);
				}
				else {
					
					P(mutex_conso);
					
					indexConso = mem + (SIZE_BUFFER * sizeof(char) + sizeof(int));
					
					printf("%c \n", mem[*indexConso]);
					
					indexConso[0] = (indexConso[0] + 1) % SIZE_BUFFER;
					
					if(shmdt(mem) == -1){
						perror("detachement impossible");
						exit(1);
					}
					
					V(mutex_conso);
				}
				/* fin lecture */
				
				// on rend la semaphore
				V(semid_prod);
			}
		}
	}
	
	return 0;
}