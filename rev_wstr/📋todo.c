Nom de l'affectation : rev_wstr
Fichiers attendus : rev_wstr.c
Fonctions autorisées : write, malloc, free
--------------------------------------------------------------------------------

Écrivez un programme qui prend une chaîne de caractères en paramètre et
imprime ses mots dans l'ordre inverse.

Un "mot" est une partie de la chaîne délimitée par des espaces et/ou des
tabulations, ou le début/la fin de la chaîne.

Si le nombre de paramètres est différent de 1, le programme affichera '\\n'.

Dans les paramètres qui seront testés, il n'y aura pas d'espaces "supplémentaires"
(cela signifie qu'il n'y aura pas d'espaces supplémentaires au début ou à la fin de
la chaîne et que les mots seront toujours séparés par exactement un espace).

Exemples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>