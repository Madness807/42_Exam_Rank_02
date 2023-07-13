// Inclusion de la bibliothèque nécessaire pour utiliser write
#include <unistd.h>

int main (int argc , char **argv)
{
	int i = 0;
	int j;
	char *str = argv[1];

	// Vérification qu'au moins un argument a été fourni lors de l'exécution
	if (argc >= 2)
	{
		// Ignore les espaces et les tabulations en début de chaîne
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		{
			i++;
		}
		// Stocke l'index du premier caractère du premier mot
		j = i; 

		while (str[i])
		{
			// Recherche la fin du mot actuel
			while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			{
				i++;
			}
			// Ignore les espaces et tabulations après le mot actuel
			while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			{
				i++;
			}
			// Si le caractère courant est le début d'un nouveau mot, l'écrit
			while (str[i] && (str[i] != ' ' && str[i] != '\t') && (str[i -1] == ' ' || str[i - 1] == '\t'))
			{
				while (str[i] && (str[i] != ' ' && str[i] != '\t'))
				{
					write (1, &str[i], 1); // Écrit le mot caractère par caractère
					i++;
				}
				write (1, " ", 1); // Ajoute un espace après le mot
				i++;
			}
		}
		// Écrit le premier mot après tous les autres mots
		while (str[j] && (str[j] != ' ' && str[j] != '\t'))
		{
			write (1, &str[j], 1);
			j++;
		}
	}
	write (1, "\n", 1); // Ajoute une nouvelle ligne à la fin
}
