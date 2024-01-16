#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // C'est une bibliothèque spécifique à Linux offrant les fonctions

// Fork d'un processus

int main (int argc, char *argv[]) {
    printf("Hello world\n");            // Affiche "Hello world"

    int id = fork();                    // On crée le fork du main et on stocke les id
    printf("Hello from %d\n", id);      // On affiche un message avec les id 

    if (id == 0) {                      // un processus fils créé par un fork a obligatoirement 0 comme id
        printf("Hello from child\n");
    } else {
        printf("Hello from parent\n");
    }
    return 0;
}