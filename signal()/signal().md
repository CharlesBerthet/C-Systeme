# Signal

Afin d'utiliser les signaux ont va utiliser la fonction `kill()`

## SIGKILL

Cela permet de terminer les processus fils

## SIGSTOP

Cela permet de mettre en pause les processus fils 

## SIGCONT

Cela permet de relancer les processus en pause

## Sigaction

Des signaux peuvent être relier à des actions précises, pour ce faire on leur créer un void contenant ce qu'ils dovient faire.

Il faut ensuite leur structure et les lier à un signal tels que SIGCONT ou SIGSTOP.

Par exemple on peut créer un handler affichant un message d'erreur et empechant le kill d'un processus avec CTRL+Z.


## Sigusr1 / Sigusr2

Ce sont des signaux qui sont réserver pour une utilisation personnelle. On peut donc les définir pour effectuer des actions spécifiques.

