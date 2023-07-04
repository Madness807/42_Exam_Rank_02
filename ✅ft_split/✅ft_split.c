#include <stdio.h>
#include <stdlib.h>

int	nb_words(char *str)
{
	int i = 0;
	int words = 0;

   while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		words++;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
			i++;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	}
	return (words);
}

void fill_word(char **dest, char *str)
{
	int i = 0;
	int j = 0;
	int words = 0;
	
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		j = 0;
		dest[words] = malloc(1000 * sizeof(char));
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
		{
			dest[words][j] = str[i];
			j++;
			i++;
		}
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		dest[words][j] = 0;
		words++;
	}
	dest[words] = 0;
}

char    **ft_split(char *str)
{
	int nbr_word;
	char **tab_str;

	nbr_word = nb_words(str);
	tab_str = malloc((nbr_word + 1) * sizeof(char *));
	fill_word(tab_str, str);
	return(tab_str);
}

int main(int argc, char **argv)
{
	int i;
	char **tab;

	tab = ft_split(argv[1]);
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}