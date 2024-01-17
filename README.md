# C Système


## Notions

- forks

- pipe

- named pipe (FIFO)

 - signaux

- Apache

- MySQL

## Codes 

- fork
    - fork()
        >Fork un processus père
    - getpid() / getppid()
        > Récupère le pid du processus et de son père et les affiche
    - wait()
        > Attend que le processus fils finisse pour que le père fasse sa partie
    - multi-forks
        > Plusieurs fork à la suite et le père attend la fin de tous pour s'arreter

- pipe
    - pipe()
        > Envoie d'un message <br>
        > Lecture du message
    - fifo()
        > Création d'un fichier <br>
        > Ecriture d'un message dans le fichier <br>
        > Lecture du message

- signal
    > Utilisation de kill()
    - sigkill
        > Tue le processus

    - sigstop
        > Met en pause le processus

    - sigcont
        > Lance les processus stopper

    - sigaction
        > Mise en place d'un signal lié à une action <br>
        > Affiche un message quand le processus revient en forground

    - sigusr
        > Mise en place d'une action spécifique sur un signal
        > Affiche un message au bout d'un certain temps