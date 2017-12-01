#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define FICHIER_PATH "fichier"
#define SORTIE_PATH "sortie"
#define STRING "toto"

// cat fichier | wc
/*
int main() {
  int pfd[2];
  int pid;
  
  pipe(pfd);
  
  pid = fork();
  
  if(pid == 0) {
    close(pfd[1]);
    dup2(pfd[0], 0);
    close(pfd[0]);
    execlp("wc", "wc", NULL);
  }
  else {
    close(pfd[0]);
    dup2(pfd[1], 1);
    close(pfd[1]);
    execlp("cat", "cat", "fichier", NULL);
  }
  
  return 0;
  
}
*/

// sort < fichier | grep chaine | tail -n 5 > sortie
int main() {
	int pipe1[2];
	int pipe2[2];
	int pidFils1, pidFils2;
	int fileDescriptorFichier, fileDescriptorSortie;

	pipe(pipe1);

	pidFils1 = fork();

	// fils 1
	if(pidFils1 == 0) {

		pipe(pipe2);
		pidFils2 = fork();

		// fils 2
		if(pidFils2 == 0){
			// on ferme ce qui existe mais dont on n'a plus besoin
			close(pipe1[0]);
			close(pipe1[1]);
			
			// on ferme l'entree de pipe2 pour lire dans la sortie + on ferme la sortie
			close(pipe2[1]);
			dup2(pipe2[0], 0);
			close(pipe2[0]);

			// ouverture fichier sortie
			fileDescriptorSortie = open(SORTIE_PATH, O_WRONLY);
			if(fileDescriptorSortie == -1) {
				printf("erreur ouverture fichier : %s", SORTIE_PATH);
				return 1;
			}

			// ecriture dans le fichier de sortie
			dup2(fileDescriptorSortie, 1);
			execlp("tail", "tail", "-n", "5", NULL);
		}
		// fils 1
		else {
			// on ferme l'entrée de pipe1 pour lire dans la sortie + on ferme la sortie
			close(pipe1[1]);
			dup2(pipe1[0], 0);
			close(pipe1[0]);
			
			// on ferme la sortie de pipe2 pour écrire dans l'entrée + on ferme l'entrée
			close(pipe2[0]);
			dup2(pipe2[1], 1);
			close(pipe2[1]);
			
			// ecriture dans l'entree de pipe 2
			execlp("grep", "grep", STRING, NULL);
		}

	}
	// père
	else {
		// on ferme la sortie de pipe1 pour écrire dans l'entrée + on ferme l'entrée
		close(pipe1[0]);
		dup2(pipe1[1], 1);
		close(pipe1[1]);

		// lecture fichier
		fileDescriptorFichier = open(FICHIER_PATH, O_RDONLY);
		if(fileDescriptorFichier == -1) {
			printf("erreur ouverture fichier : %s", FICHIER_PATH);
			return 1;
		}

		// ecriture dans le fichier
		dup2(fileDescriptorFichier, 0);
		execlp("sort", "sort", NULL);
	}

	return 0;

}