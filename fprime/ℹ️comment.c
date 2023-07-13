// Inclusion des bibliothèques standard nécessaires
#include <stdio.h>
#include <stdlib.h>

// Fonction pour vérifier si un nombre est premier
int		is_prime(int n)
{
	int i = 2; // Initialisation de la variable qui va servir à diviser le nombre

	while (i < n) // Tant que le diviseur est inférieur au nombre
	{
		if (n % i == 0) // Si le nombre est divisible par i (donc n'est pas premier)
			return (0); // On retourne 0 (faux)
		++i; // On incrémente le diviseur
	}
	return (1); // Si aucune division n'a été exacte, le nombre est premier, donc on retourne 1 (vrai)
}

// Fonction pour afficher la factorisation d'un nombre en facteurs premiers
void	fprime(char *str)
{
	int n = atoi(str);  // Conversion de la chaîne en entier
	int factor = 2;  // Premier facteur à tester
	int first = 1;  // Variable pour gérer l'affichage (voir plus bas)

	if (n == 1) // Si le nombre est 1
		printf("1"); // On affiche 1, car c'est le seul facteur de 1

	// On teste tous les entiers jusqu'à n
	while (factor <= n)
	{
		// Si factor est un diviseur de n et que factor est un nombre premier
		if (n % factor == 0 && is_prime(factor))
		{
			// Si c'est le premier facteur qu'on affiche, on n'a pas besoin de '*'
			if (first == 1)
				printf("%d", factor);
			else // Sinon, on précède le facteur d'un '*'
				printf("*%d", factor);

			first = 0; // On indique que le premier facteur a été affiché
			n = n / factor; // On divise n par le facteur pour simplifier la factorisation
		}
		else // Si factor n'est pas un facteur de n, on passe au nombre suivant
			++factor;
	}
}

// Programme principal
int		main(int argc, char **argv)
{
	if (argc == 2) // Si on a un argument
		fprime(argv[1]); // On appelle la fonction fprime avec cet argument

	printf("\n"); // On affiche un saut de ligne
	return (0); // Fin du programme
}
