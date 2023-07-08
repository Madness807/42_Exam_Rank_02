#include "flood_fill.h"

// Fonction de remplissage récursive.
void f_fill(char **tab, t_point size, char target, int row, int col)
{
    // Vérifie si l'indice est hors limites.
    if (row < 0 || col < 0 || row >= size.y || col >= size.x)
        return;
    // Si la cellule actuelle est déjà remplie ou si ce n'est pas le caractère cible,
    // alors on sort de la fonction.
    if (tab[row][col] == 'F' || tab[row][col] != target)
        return;
    // Remplace le caractère cible dans la cellule actuelle par 'F'.
    tab[row][col] = 'F';

    // Appel récursif pour les cellules voisines.
    f_fill(tab, size, target, row - 1, col); // en haut
    f_fill(tab, size, target, row + 1, col); // en bas
    f_fill(tab, size, target, row, col - 1); // à gauche
    f_fill(tab, size, target, row, col + 1); // à droite
}

// Fonction principale pour effectuer le remplissage.
void  flood_fill(char **tab, t_point size, t_point begin)
{
    // Récupère le caractère cible à partir du point de départ.
    char target = tab[begin.y][begin.x];
    
    // Appel de la fonction récursive pour remplir les cellules connectées.
    f_fill(tab, size, target, begin.y, begin.x);
}
