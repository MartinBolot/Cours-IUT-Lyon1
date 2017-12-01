#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handleSignalInteruption(int sign);

int fin = 0;

int main() {
	signal(SIGINT, handleSignalInteruption);
	
	for(;;){
		printf("boucle infinie \n");
		if(fin == 1) { break; }
	};
	return 0;
}

void handleSignalInteruption(int sign) {
	printf("Indentifiant du signal reçu : %d \n", sign);
	fin = 1;
}