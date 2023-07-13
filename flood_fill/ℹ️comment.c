// Définition d'une structure pour représenter un point dans un espace à deux dimensions
typedef struct s_point
{
    int x; // Coordonnée x du point
    int y; // Coordonnée y du point
}t_point;

// Fonction récursive pour remplir les espaces contigus d'un tableau avec le caractère 'F'
void f_fill(char **tab, t_point size, char target, int row, int col)
{
    // Si les indices de ligne ou de colonne dépassent les limites du tableau, on retourne sans rien faire
    if (row < 0 || col < 0 || row >= size.y || col >= size.x)
        return;

    // Si la cellule actuelle a déjà été remplie ou n'a pas le caractère cible, on retourne sans rien faire
    if (tab[row][col] == 'F' || tab[row][col] != target)
        return;
    
    // On remplace le caractère de la cellule actuelle par 'F'
    tab[row][col] = 'F';

    // On appelle récursivement la fonction sur les cellules adjacentes (haut, bas, gauche, droite)
    f_fill(tab, size, target, row -1, col); // Cellule au-dessus
    f_fill(tab, size, target, row +1, col); // Cellule en-dessous
    f_fill(tab, size, target, row, col - 1); // Cellule à gauche
    f_fill(tab, size, target, row, col + 1); // Cellule à droite
}

// Fonction principale pour démarrer l'opération de remplissage
void  flood_fill(char **tab, t_point size, t_point begin)
{
    // On détermine le caractère cible à remplacer en récupérant le caractère à la position de départ
    char target = tab[begin.y][begin.x];

    // On appelle la fonction de remplissage avec le caractère cible et la position de départ
    f_fill(tab, size, target, begin.y, begin.x);
}
