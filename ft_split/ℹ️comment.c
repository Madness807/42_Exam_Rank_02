// Inclusion des bibliothèques standard nécessaires
#include <stdio.h>
#include <stdlib.h>

// Fonction pour compter le nombre de mots dans une chaîne de caractères
int	nb_words(char *str)
{
	int i = 0;
	int words = 0;

	// On ignore les espaces en début de chaîne
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;

	// On parcourt la chaîne de caractères
	while (str[i])
	{
		// On compte un mot
		words++;

		// On ignore les caractères non-espaces
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
			i++;

		// On ignore les espaces
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	}
	// On retourne le nombre de mots
	return (words);
}

// Fonction pour remplir un tableau de chaînes de caractères avec les mots de la chaîne source
void fill_word(char **dest, char *str)
{
	int i = 0;
	int j = 0;
	int words = 0;

	// On ignore les espaces en début de chaîne
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;

	while (str[i])
	{
		j = 0;
		// On alloue de la mémoire pour le mot suivant
		dest[words] = malloc(1000 * sizeof(char));

		// On copie le mot dans la mémoire allouée
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
		{
			dest[words][j] = str[i];
			j++;
			i++;
		}

		// On ignore les espaces
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;

		// On termine la chaîne de caractères par un zéro
		dest[words][j] = 0;
		words++;
	}

	// On termine le tableau de chaînes de caractères par un zéro
	dest[words] = 0;
}

// Fonction pour diviser une chaîne de caractères en mots
char **ft_split(char *str)
{
	int nbr_word;
	char **tab_str;

	// On compte le nombre de mots dans la chaîne source
	nbr_word = nb_words(str);

	// On alloue de la mémoire pour le tableau de chaînes de caractères
	tab_str = malloc((nbr_word + 1) * sizeof(char *));

	// On remplit le tableau de chaînes de caractères avec les mots de la chaîne source
	fill_word(tab_str, str);

	// On retourne le tableau de chaînes de caractères
	return(tab_str);
}

// Programme principal
int main(int argc, char **argv)
{
	int i;
	char **tab;

	// On divise le premier argument en mots
	tab = ft_split(argv[1]);

	i = 0;
	// On affiche tous les mots
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0); // Fin du programme
}
