# Pipe

Un pipe permet de communiquer entre un processus parent et un processus enfant.

Pour commniquer on a la variable `fd` qui contient 2 valeurs soit `0 pour la lecture` soir `1 pour l'écriture`.

## Envoie de message

Un processus ne doit avoir qu'une action ouverte, donc si un processus enfant veut écrire il faudra fermer le fd[0] lier a la lecture.

Ensuite, il faut spécifier que l'on écrit, renseigner la variable contenant le message (plus simple pour la manipulation) et sa longueur (avec un sizeof).

A la fin de son écriture, il faut également le fermer.

## Reception de message

Tout comme l'envoi, il faut fermer ce qui n'est pas utiliser, soit l'écriture.

Ensuite, on lit le message en le mettant dans la variable de réponse.

Une fois cela fait, on ferme la lecture et l'on peut utiliser la variable pour l'afficher avec un print.

Il est possible de regarder le message pour envoyer une réponse différente : <br>
- Si le message reçu est le int 0 alors il renvoi quelque chose
- Si le message reçu est le int 1 il renvoi une autre réponse


# Named Pipe (FIFO)

Il s'agit du meme principe qu'un pipe classique cependant il utilise un fichier.

Tout d'abord il faut créer un fichier avec les droits voulu.

Puis on peut le manipuler avec différentes options :

- O_RDONLY = Lecture seule

- O_WRONLY = Ecriture seule

- O_RDWR = Lecture et Ecriture

- O_CREAT = Crée le fichier s'il n'existe pas 

- O_APPEND = Ecrit à la suite du fichier

- O_TRUNC = Vide le fichier à l'ouverture

