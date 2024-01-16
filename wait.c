#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // C'est une bibliothèque spécifique à Linux offrant les fonctions


// Attendre la fin d'un processus

int main (int argc, char *argv[]) {

    int id = fork();                    // On crée le fork du main et on stocke les id
    int n;                              // On initie une variable pour compter jusqu'à 10
    if (id == 0) {
        n = 1;                          // L'enfant comptera de 1 à 5
    }
    else {
        n = 6;                          // Le parent comptera de 6 à 10
    }

    if (id != 0) {
        wait();                         // On dit au parent d'attendre la fin de l'enfant
    }

    int i;
    for (i = n; i < n + 5; i++) {
        printf("%d", i);                // On affiche les nombres de 1 à 10
        fflush(stdout);                 // On vide le buffer pour afficher les nombres un par un
    }

    return 0;

}