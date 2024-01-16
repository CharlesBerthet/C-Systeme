#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // C'est une bibliothèque spécifique à Linux offrant les fonctions de fork
#include <sys/wait.h>   // C'est une bibliothèque spécifique à Linux offrant les fonctions de pid
#include <errno.h>      // C'est une bibliothèque spécifique à Linux offrant les fonctions de errno

int main(int argc, char *argv) {

    int fd[2];                                  // On crée une variable pour le pipe avec 0 pour lecture et 1 pour écriture
    pipe(fd);                                   // On crée le pipe
    char reponse[50]                            // On crée une variable pour stocker la réponse

    int id = fork();                            // On crée le fork du main et on stocke les id

    if(id == 0) {
        char phrase[] = "Hello World";          // On crée une variable pour stocker la phrase
        close(fd[0]);                           // On ferme la lecture du pipe
        write(fd[1],&phrase,sizeof(phrase));    // On écrit dans le pipe avec le fd à 1, on spécifie la phrase et sa longueur
        close(fd[1]);                           // On ferme l'écriture du pipe
    }
    else {
        close(fd[1]);                           // On ferme l'écriture du pipe
        read(fd[0],&reponse,sizeof(reponse));   // On lit dans le pipe avec le fd à 0, on spécifie la réponse et sa longueur
        close(fd[0]);                           // On ferme la lecture du pipe

        printf("%s\n",reponse);                 // On affiche la réponse
    }

    exit(EXIT_SUCCESS);             // Kill tout les processus
    return 0;
}