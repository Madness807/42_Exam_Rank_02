// Inclusion des bibliothèques nécessaires
#include <stdio.h>
#include <stdlib.h>

// Fonction de tri par ordre croissant
void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int tmp;

	i = 0;

	// Vérifie si le tableau n'est pas NULL
	if (tab != NULL)
	{
		// Parcourt tout le tableau
		while (i < size)
		{
			// Si l'élément actuel est supérieur à l'élément suivant
			if (tab[i] > tab[i + 1])
			{
				// On échange leurs positions
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				i = -1; // On réinitialise l'indice pour recommencer le parcours du tableau
			}
			i++; // On avance dans le tableau
		}
	}
}

int	main(int argc, char **argv)
{
	int *tab; // Pointeur vers le tableau d'entiers
	unsigned int size; // Taille du tableau
	int i;

	// Calcul de la taille du tableau en fonction des arguments
	size = argc -1;

	// Allocation de mémoire pour le tableau
	tab = malloc (size * sizeof (int));

	// Remplissage du tableau avec les arguments convertis en entiers
	i = 0;
	while (i < (size))
	{
		tab[i] = atoi(argv[i + 1]);
		i++;
	}

	// Tri du tableau
	sort_int_tab(tab, size - 1);

	// Affichage du tableau
	i = 0;
	while(tab[i])
	{
		printf("%i\n", tab[i]);
		i++;
	}
	return (0); // Fin du programme
}
