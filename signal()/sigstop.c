#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // C'est une bibliothèque spécifique à Linux offrant les fonctions de fork
#include <sys/wait.h>   // C'est une bibliothèque spécifique à Linux offrant les fonctions de pid
#include <errno.h>      // C'est une bibliothèque spécifique à Linux offrant les fonctions de errno
#include <signal.h>     // C'est une bibliothèque spécifique à Linux offrant les fonctions de signal

int main(int argc, char *argv) {
    
    int id = fork();                    // On crée le fork du main et on stocke les id

    if (id == 0) {
        while (1) {
            printf("Je suis le fils\n");    // On affiche un message en boucle
            sleep(1);
        }
    }
    else {
        sleep(5);                           // On attend 5 secondes
        kill(id, SIGSTOP);                  // On stop le processus fils
        sleep(1);                           // On attend 1 secondes
        kill(id, SIGCONT);                  // On relance le processus fils
        sleep(5);                           // On attend 5 secondes
        kill(id, SIGKILL);                  // On tue le fils
        wait(NULL);
    }

    exit(EXIT_SUCCESS);                 // Kill tout les processus
    return 0;
}