#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // C'est une bibliothèque spécifique à Linux offrant les fonctions de fork
#include <sys/wait.h>   // C'est une bibliothèque spécifique à Linux offrant les fonctions de pid
#include <errno.h>      // C'est une bibliothèque spécifique à Linux offrant les fonctions de errno

int main (int argc, char *) {

        int id1 = fork();                               // On crée le fork du main et on stocke les id
        int id2 = fork();                               // On crée le fork du main et les enfants du premier fork et on stocke les id

        if (id1 == 0) {
            if (id2 == 0) {
                printf("Je suis le petit fils\n");      // On affiche un message si on est le petit fils
            } 
            else {
                printf("Je suis le fils\n");            // On affiche un message si on est le fils
            }
        } 
        else {
            if (id2 == 0) {
                printf("Je suis le petit fils\n");      // On affiche un message si on est le petit fils
            } 
            else {
                printf("Je suis le père\n");            // On affiche un message si on est le père
            }
        }

        while (wait(NULL) != -1 || errno != ECHILD) {   // On attend la fin de tout les enfants
            printf("Plus d'enfant à attendre\n");       // Le parent affiche un message si l'enfant est terminé
        }

    exit(EXIT_SUCCESS);                 // Kill tout les processus
    return 0;
}