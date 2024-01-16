#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // C'est une bibliothèque spécifique à Linux offrant les fonctions de fork
#include <sys/wait.h>   // C'est une bibliothèque spécifique à Linux offrant les fonctions de pid
#include <errno.h>      // C'est une bibliothèque spécifique à Linux offrant les fonctions de errno

int main(int argc, char *argv) {

    mkfifo("fichier", 0666);            // On crée le fifo avec son nom et ses droits

    int id = fork();                    // On crée le fork du main et on stocke les id
    char reponse[50]                    // On crée une variable pour stocker la réponse

    if(id == 0) {
        char phrase[] = "Hello World";          // On crée une variable pour stocker la phrase
        int fd = open("fichier", O_WRONLY);     // On ouvre le fifo en écriture
        write(fd,&phrase,sizeof(phrase));       // On écrit dans le pipe avec le fd, on spécifie la phrase et sa longueur
        close(fd);                              // On ferme le fifo
    }
    else {
        int fd = open("fichier", O_RDONLY);     // On ouvre le fifo en lecture
        read(fd,&reponse,sizeof(reponse));      // On lit dans le pipe avec le fd, on spécifie la réponse et sa longueur
        close(fd);                              // On ferme le fifo

        printf("%s\n",reponse);                 // On affiche la réponse
    }

    exit(EXIT_SUCCESS);             // Kill tout les processus
    return 0;
}