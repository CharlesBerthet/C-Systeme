#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // C'est une bibliothèque spécifique à Linux offrant les fonctions de fork
#include <sys/wait.h>   // C'est une bibliothèque spécifique à Linux offrant les fonctions de pid
#include <errno.h>      // C'est une bibliothèque spécifique à Linux offrant les fonctions de errno
#include <signal.h>     // C'est une bibliothèque spécifique à Linux offrant les fonctions de signal


// Le processus fils interragit avec le processus père grace au signal SIGUSR1

void handler_sigusr1(int sig) {                        // On crée une fonction handler qui prend en paramètre un signal
    if (x == 0) {
        printf("Tu vas y arriver\n");              // On affiche un message
    }
}

int x = 0;                                  // On crée une variable globale pour le calcul

int main(int argc, char *argv) {


    int id = fork();                    // On crée le fork du main et on stocke les id

    if (id == 0) {
        sleep(5);                           // On attend 5 secondes
        kill(getppid(), SIGUSR1);           // On envoie le signal SIGUSR1 au père
    }
    else {

        struct sigaction sa = {0};          // On crée une structure sigaction
        sa.sa_flags = SA_RESTART;           // On lui attribue le flag SA_RESTART
        sa.sa_handler = &handler_sigusr1;   // On lui attribue la fonction handler
        sigaction(SIGUSR1, &sa, NULL);      // On lui attribue le signal SIGUSR1

        printf("Que fait 3 * 5 ?\n");           // On affiche un message
        scanf("%d", &id);                // On récupère la réponse

        if (x == 15) {
            printf("Bonne réponse\n");          // On affiche un message
        }
        else {
            printf("Mauvaise réponse\n");        // On affiche un message
        }
    }

    exit(EXIT_SUCCESS);                 // Kill tout les processus
    return 0;
}