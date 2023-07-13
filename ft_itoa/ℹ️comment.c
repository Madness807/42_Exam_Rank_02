// Inclusion des bibliothèques standard nécessaires
#include <stdlib.h>
#include <stdio.h>

// Fonction qui retourne la valeur absolue d'un entier
int		absolute_value(int nbr)
{
	if (nbr < 0) // Si le nombre est négatif
		return (-nbr); // On retourne son opposé (qui sera positif)
	return (nbr); // Sinon on retourne le nombre tel quel
}

// Fonction qui détermine la longueur d'un entier (nombre de chiffres)
int		get_len(int nbr)
{
	int	len = 0;
	if (nbr <= 0) // Si le nombre est négatif ou nul, on commence à compter à partir de 1
		len++;
	while (nbr != 0) // Tant que le nombre n'est pas nul
	{
		nbr = nbr / 10; // On le divise par 10 pour enlever le dernier chiffre
		len++; // On incrémente le compteur
	}
	return (len); // On retourne le compteur
}

// Fonction qui convertit un entier en une chaîne de caractères
char	*ft_itoa(int nbr)
{
	char *res; // Variable qui va contenir la chaîne finale
	int len = 0; // Longueur du nombre

	len = get_len(nbr); // On récupère la longueur du nombre
	res = malloc((len +1) * sizeof (char)); // On alloue de la mémoire pour la chaîne
	res[len] = '\0'; // On met un caractère de fin de chaîne à la fin

	if (nbr < 0) // Si le nombre est négatif
		res[0] = '-'; // On met un '-' au début de la chaîne
	else if (nbr == 0) // Si le nombre est nul
		res[0] = '0'; // On met un '0' dans la chaîne
	
	while (nbr != 0) // Tant que le nombre n'est pas nul
	{
		res[len - 1] = absolute_value(nbr % 10) + '0'; // On prend le chiffre des unités, on le convertit en caractère et on l'ajoute à la chaîne
		nbr = nbr / 10; // On enlève le chiffre des unités
		len--; // On décrémente la longueur du nombre
	}
	return (res); // On retourne la chaîne de caractères
}

// Programme principal
int	main(int argc, char **argv)
{
	printf("%s\n", ft_itoa(atoi(argv[1]))); // On convertit le premier argument en entier, puis en chaîne, et on l'affiche
    return (0); // Fin du programme
}
