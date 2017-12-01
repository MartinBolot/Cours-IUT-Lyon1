#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handleSignalInteruption(int sign);

int main() {
	
	int i = 0;
	int pidFils;
	
	pidFils = fork();
	// fils
	if(!pidFils) {
		signal(SIGUSR1, handleSignalInteruption);
		signal(SIGUSR2, handleSignalInteruption);
		for(;;);
	}
	// père
	else {
		for(i = 0; i <=10; i++) {
			printf("père : %d \n", i);
			if(i == 3 || i == 5) {
				kill(pidFils, SIGUSR1);
			}
			sleep(1);
		}
		kill(pidFils, SIGUSR2);
	}
	return 0;
}

void handleSignalInteruption(int sign) {
	printf("Signal d'interruption reçu : %d \n", sign);
	if(sign == SIGUSR1) {
		printf("fils \n");
		sleep(1);
	}
	else if(sign == SIGUSR2) {
		exit(0);
	}
}