#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // C'est une bibliothèque spécifique à Linux offrant les fonctions de fork
#include <sys/wait.h>   // C'est une bibliothèque spécifique à Linux offrant les fonctions de pid
#include <errno.h>      // C'est une bibliothèque spécifique à Linux offrant les fonctions de errno
#include <signal.h>     // C'est une bibliothèque spécifique à Linux offrant les fonctions de signal


// On peut mettre en background le processus avec CTRL + Z et le remettre en foreground avec la commande fg il sera toujours présent

void handler_sigcont(int sig) {                        // On crée une fonction handler qui prend en paramètre un signal
    printf("Inscrire nombre : ");              // On affiche un message
    fflush(stdout);
}

int main(int argc, char *argv) {

    struct sigaction sa;                        // On crée une structure sigaction
    sa.sa_handler = &handler_sigcont;           // On lui attribue la fonction handler
    sa.sa_flags = SA_RESTART;                   // On lui attribue le flag SA_RESTART
    sigaction(SIGCONT, &sa, NULL);              // On lui attribue le signal SIGCONT 

    int x;
    printf("Inscrire nombre : ");
    scanf("%d", &x);
    printf("Nombre : %d * 5 =  %d\n", x, x*5);

    return 0;

}