#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handleSignalInteruption(int sign);

int main() {
	
	int i = 0;
	int pidFils;
	
	//signal(SIGINT, handleSignalInteruption);
	
	pidFils = fork();
	// fils
	if(!pidFils) {
		for(;;) {
			printf("fils \n");
			sleep(1);
		}
	}
	// père
	else {
		for(i = 0; i <=3; i++) {
			printf("père : %d \n", i);
			sleep(1);
		}
		kill(pidFils, SIGKILL);
	}
	return 0;
}

void handleSignalInteruption(int sign) {
}