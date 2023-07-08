Nom de l'assignement : rostring
Fichiers attendus : rostring.c
Fonctions autorisées : write, malloc, free
--------------------------------------------------------------------------------

Écrivez un programme qui prend une chaîne de caractères et affiche cette chaîne après l'avoir tournée d'un mot vers la gauche.

Ainsi, le premier mot devient le dernier, et les autres restent dans le même ordre.

Un "mot" est défini comme une partie d'une chaîne de caractères délimitée soit par des espaces/tabulations, soit par le début/fin de la chaîne.

Les mots seront séparés par un seul espace dans la sortie.

S'il y a moins d'un argument, le programme affiche \\n.

Exemple :

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>