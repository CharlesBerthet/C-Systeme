# Fork

**Fonction `fork()`** : <br>

La fonction `fork()` permet de créer un processus enfant depuis un processus parent. <br>
Une fois créer tout le reste du programme sera éxécuté dans les deux processus.

On peut exécuter des bouts de code dans un seul des processus en le spécifiant avec son id.


## ID

Un enfant aura toujours l'id 0 

On peut donc dissocier le parent de l'enfant par une variable `id`.

Si `id = 0` alors on sera dans le processus enfant 

Si `id != 0` alors on sera dans le processus parent


## PID

Chaque processus possède un `PID`

On peut les afficher avec la fonction `getpid()`. 

On peut également afficher le PID de son parent avec `getppid()`

Normalement le processus enfant aura un PID plus grand que le processus parent et aura ce dernier comme PID parent.

**Attention :** si le processus parent est kill avant l'enfant, ce dernier changera de PID parent et se ratachera à un autre processus.


## Wait

Afin de ne pas kill le processus parent alors que des processus enfants n'ont pas fini on peut utiliser `wait()`

Avec un simple `wait()` le processus parent attendra le fin d'un seul processus.

S'il y a plusieurs processus à attendre on peut rajouter `errno != ECHILD` qui vérifiera que tout les processus enfants sont terminés


## Multi-fork

Si un second fork est exécuté, alors le processus parent aura un deuxième enfant et le premier enfant devient parent d'un nouveau processus enfant

Le processus parent original ne peut pas communiquer directement avec l'enfant de son premier enfant.