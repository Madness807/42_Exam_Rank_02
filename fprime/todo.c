Nom de l'affectation : fprime
Fichiers attendus : fprime.c
Fonctions autorisées : printf, atoi
--------------------------------------------------------------------------------

Écrivez un programme qui prend un entier positif et affiche ses facteurs 
premiers sur la sortie standard, suivis d'un saut de ligne.

Les facteurs doivent être affichés dans 
l'ordre croissant et séparés par '*', de sorte que l'expression dans la sortie donne le bon résultat.

Si le nombre de paramètres n'est pas égal à 1, affichez simplement un saut de ligne.

L'entrée, lorsqu'il y en a une, sera valide.

Exemples :

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$