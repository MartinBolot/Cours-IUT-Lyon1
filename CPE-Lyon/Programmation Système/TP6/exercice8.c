#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define TIMER_COUNT 5
#define MAX_LENGTH 100


int main() {
	// si on dépasse max_length, on casse tout
	char input[MAX_LENGTH] ;
	int i = 0;
	int ok = 0;
	int pidFils1 = 0;
	int pidFils2 = 0;
	int etat = 0;
	
	pidFils1 = fork();
	
	// fils
	if(pidFils1 == 0){
		
		pidFils2 = fork();
		
		// fils 2 (le timer)
		if(pidFils2 == 0) {
			for(i = 0; i < TIMER_COUNT; i++) {
				printf("Secondes restantes : %d \n", TIMER_COUNT-i);
				sleep(1);
			}
			printf("Trop tard \n");
			// on tue le fils qui gère le prompt
			kill(pidFils1, SIGKILL);
			exit(0);
		}
		// fils 1 (le prompt)
		else {
			printf("Veuillez entrer un entier dans le temps imparti : %d \n", TIMER_COUNT);
			do{
				printf("Svp un entier : \n");
				ok = scanf("%s", input);
			} while (!atoi(input));
			// on tue le fils qui gère le timer car on a gagné
			kill(pidFils2, SIGKILL);
			printf("Entier OK \n");
		}
		
	}
	// père
	else {
		wait(&etat);
	}
	
	return 0;
}