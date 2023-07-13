// Inclusion de la bibliothèque nécessaire pour utiliser write
#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int k;
	int first_word;
	char *str;

	// Si un argument a été passé à l'exécution
	if (argc == 2)
	{
		i = 0;
		first_word = 1; // Variable pour vérifier si c'est le premier mot
		str = argv[1]; // On pointe sur la chaîne de caractères passée en argument

		// Parcourt la chaîne jusqu'à la fin
		while (str[i])
			i++;

		// Parcourt la chaîne de caractères à l'envers
		while (i >= 0)
		{
			// Recherche le début du mot précédent (ou le début de la chaîne)
			while (i >= 0 && (str[i] != ' ' && str[i] != '\t'))
				i--;

			k = i + 1; // Indice de début du mot

			// Si ce n'est pas le premier mot, on écrit un espace avant le mot
			if (first_word == 0)
				write(1, " ",1);

			// Ecrit le mot dans le terminal
			while (str[k] && str[k] != ' ' && str[k] != '\t')
			{
				write (1, &str[k], 1);
				k++;
			}

			first_word = 0; // Il ne s'agit plus du premier mot
			i--; // On décrémente l'indice pour passer au mot précédent
		}
	}
	write(1, "\n", 1); // Écrit un saut de ligne dans le terminal
}
