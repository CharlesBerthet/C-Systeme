# Fork

La fonction `fork()` permet de dubliquer un processus.

Lorsque que l'on fork un processus, un enfant identique est créé, dès qu'un fork apparait dans un programme, la suite de ce dernier sera exécuté dans le processus parent et tout les enfants qui ont été créés.

Un processus enfant à toujours un id égal à 0.

L'enfant hérite de l'espace d'adressage, des données etc de son parent. <br>
Cependant, les modifications de la mémoire de l'un n'affecte pas les autres