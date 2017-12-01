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
	int testExec;
	mode_t mode = S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH;
	
	//dup2()
	
	if(argc > 2){
		fd = open(argv[1],O_CREAT|O_RDWR,mode);
		if(fd==-1){
			printf("erreur lors de l ouverture du ficher \n");fflush(stdout);
		}else{
			if(strcmp(argv[0],"redir0") == 0 || strcmp(argv[0],"./redir0") == 0){
				redirection = dup2(fd,0);
			}else if(strcmp(argv[0],"redir1") == 0 || strcmp(argv[0],"./redir1") == 0){
				redirection = dup2(fd,1);
			}else if(strcmp(argv[0],"redir2") == 0 || strcmp(argv[0],"./redir2") == 0){
				redirection = dup2(fd,2);
			}else{
				printf("erreur : la redirection doit etre faite vers 0,1 ou 2 \n");fflush(stdout);
				exit(1);
			}

			if(redirection==-1){
				printf("erreur lors de la redirection \n");fflush(stdout);
			}
		}
		testExec = execvp(argv[2],(argv+2));
		if(testExec == -1){
			perror("Erreur : la commande nexiste pas");
			return 1;
		}
	} else{
		printf("nombre de parametres insuffisant \n");fflush(stdout);
		printf("usage : file command [-arguments] \n");fflush(stdout);
	}

	return 0;

}
