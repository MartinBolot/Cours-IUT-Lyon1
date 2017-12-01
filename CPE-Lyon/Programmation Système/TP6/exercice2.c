#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void stopProcess(int sign);

int main() {
	signal(SIGINT, SIG_IGN);
	
	for(;;){
		printf("boucle infinie \n");
	};
	return 0;
}

void stopProcess(int sign) {
	printf("Arrêt du processus \n");
	printf("Indentifiant du signal reçu : %d \n", sign);
	exit(sign);
}