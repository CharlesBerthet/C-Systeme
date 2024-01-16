#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // C'est une bibliothèque spécifique à Linux offrant les fonctions de fork
#include <sys/wait.h> // C'est une bibliothèque spécifique à Linux offrant les fonctions de pid

int main (int argc, char *argv) {

    int id = fork();                                // On crée le fork du main et on stocke les id

    // Si le sleep est activé, l'enfant sera exécuté apres la fin du parent, il aura donc un parent différent (Car le parent sera terminé et n'éxistera plus)
    if (id == 0) {
        sleep(5);                                   // On fait dormir l'enfant pendant 5 secondes
    }

    printf("Current ID : %d", getpid());            // On affiche l'id du processus courant
    printf(" Parent ID : %d", getppid());           // On affiche l'id du processus parent

    if (wait(NULL) == -1) {                         // On attend la fin de l'enfant
        printf("Plus d'enfant à attendre\n");       // Le parent affiche un message si l'enfant est terminé
    }

    exit(EXIT_SUCCESS);                 // Kill tout les processus
    return 0;
}