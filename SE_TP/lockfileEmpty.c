#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFF_SIZE 30
#define VARIANT_LOCK 2	//0: pas de verrouillage 1: verrouillage bloquant 2: tentative de verrouillage (non bloquant)

//typedef struct contact contact;
struct contact
{
    int id;                		//ID suppose unique
    char name[BUFF_SIZE];        	//Le nom de famille
    char firstName[BUFF_SIZE];   	//Le prenom
};


struct contact litUneEntree(int fd);
void scanContact(struct contact* unContact);
void affichage(char* fileName);
void ajout(char* fileName);
void affichageEntree(char* fileName);
void modificationEntree(char* fileName);
int verrouillage(int fd, int offset, int variant);
void deverrouillage(int fd, int offset);

void usage(char* string)
{
    fprintf(stderr,"Usage: %s fileName\n",string);
    exit(1);
}

int main(int argc, char* argv[])
{
    char fileName[256];
    int choix;

    if(argc<2) usage(argv[0]);

    strcpy(fileName,argv[1]);

    while(1)
    {
        printf(" 0-quit\n 1-Affichage complet\n 2-Affichage i-eme entree\n 3-Ajout d'une entree\n 4-Modification i-eme entree\n");
        printf("Choix: "); fflush(stdout);
        scanf("%d",&choix);

        switch(choix)
        {
            case 0:     exit(0);

            case 1:     affichage(fileName);
                        break;
            case 2:     affichageEntree(fileName);
                        break;
            case 3:     ajout(fileName);
                        break;
            case 4:     modificationEntree(fileName);
                        break;

            default:    fprintf(stderr,"Choix incorrect\n");
        }
    }

    return(0);
}//fin du main

//Lit une entree struct contact dans le fichier pointe par le descripteur fd
struct contact litUneEntree(int fd){
	char* buffer[10];
	int lecture = read(fd,buffer,sizeof(struct contact));
}//fin de affiche

//Met a jour un contact saisit au clavier
void scanContact(struct contact* unContact)
{
    printf("id: ");fflush(stdout);
    scanf("%d",&unContact->id);
    printf("First name: ");fflush(stdout);
    scanf("%s",unContact->firstName);
    printf("Name: ");fflush(stdout);
    scanf("%s",unContact->name);

}//fin de scanContact

//Affiche la totalite du fichier 
void affichage(char* fileName)
{
	
}

//Demande a l'utilisateur le numero de l'entree (ieme entree dans le fichier) a afficher puis l'affiche
void affichageEntree(char* fileName)
{
	int entree=0;
	do{
		printf("entree a lire : ");
		scanf("%d",&entree);
		while(getchar()!='\n');
	}while(entree<0);
	
	int openFile = open(fileName, O_CREAT|O_APPEND|O_WRONLY, 664);
	lseek(openFile,(sizeof(struct contact)*(entree-1)),SEEK_SET);
	litUneEntree(openFile);
}


//Ajoute une entree en fin de fichier
void ajout(char* fileName)
{
	int openFile = open(fileName, O_CREAT|O_APPEND|O_WRONLY, 664);
	
	struct contact newContact;
	scanContact(&newContact);
	write(openFile,&newContact,sizeof(struct contact));
}


//Modifie une entree donnee 
void modificationEntree(char* fileName)
{

}//fin de modificationEntree

//Variant 0: pas de lock
//Variant 1: lock bloquant
//Variant 2: lock non-bloquant
int verrouillage(int fd, int offset, int variant)
{

    return(0);
}

//Deverouille -> Attention a l'offset: un offset invalide peut creer des petits bouts de fichier verrouille.
void deverrouillage(int fd, int offset)
{

}



