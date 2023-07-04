#include <stdio.h> // Inclut les fonctions standards d'entrée/sortie.
#include <stdlib.h> // Inclut les fonctions générales, comme atoi().

// Fonction pour vérifier si un nombre est premier.
int		is_prime(int n)
{
	int i = 2; // Initialise le compteur à 2, le plus petit nombre premier.

	// Parcourt tous les nombres jusqu'à n pour vérifier s'ils sont des facteurs de n.
	while (i < n)
	{
		// Si n est divisible par i, alors n n'est pas premier.
		if (n % i == 0)
			return (0);
		++i; // Incrémente le compteur.
	}
	// Si aucun facteur n'a été trouvé, n est premier.
	return (1);
}

// Fonction pour imprimer les facteurs premiers d'un nombre.
void	fprime(char *str)
{
	int n = atoi(str); // Convertit la chaîne d'entrée en un nombre entier.
	int factor = 2; // Initialise le facteur à 2, le plus petit nombre premier.
	int first = 1; // Variable utilisée pour contrôler l'affichage.

	// Si le nombre est 1, son seul facteur est 1.
	if (n == 1)
		printf("1");

	// Parcourt tous les nombres jusqu'à n pour trouver les facteurs premiers.
	while (factor <= n)
	{
		// Si factor est un facteur premier de n...
		if (n % factor == 0 && is_prime(factor))
		{
			// ...il l'imprime. S'il s'agit du premier facteur, il ne préfixe pas avec '*'.
			if (first == 1)
				printf("%d", factor);
			else
				printf("*%d", factor);
			first = 0; // Marque que le premier facteur a été imprimé.
			n = n / factor; // Divise n par le facteur trouvé pour continuer la recherche.
		}
		else
			++factor; // Si le facteur actuel n'est pas un facteur de n, passe au suivant.
	}
}

// Fonction principale.
int		main(int argc, char **argv)
{
	// Si un argument est passé à la commande...
	if (argc == 2)
		fprime(argv[1]); // ...il appelle la fonction fprime avec cet argument.

	printf("\n"); // Imprime un saut de ligne à la fin.
	return (0); // Retourne 0, indiquant que le programme s'est terminé sans erreur.
}
