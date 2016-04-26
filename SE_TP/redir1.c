#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv){
	
	//int commandToExecute;		/* variable de test pour le retour de l'exec */
	int fd;
	int redirection;
	mode_t mode = S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH;
	
	//dup2()
	
	if(argc > 2){
		fd = open(argv[1],O_CREAT|O_RDWR,mode);
		if(fd==-1){
			printf("erreur lors de l ouverture du ficher \n");fflush(stdout);
		}else{
			redirection = dup2(fd,1);
			if(redirection==-1){
				printf("erreur lors de la redirection \n");fflush(stdout);
			}
		}
		execvp(argv[2],(argv+2));
	} else{
		printf("nombre de parametres insuffisant \n");fflush(stdout);
		printf("usage : file command [-arguments] \n");fflush(stdout);
	}

	return 0;

}
