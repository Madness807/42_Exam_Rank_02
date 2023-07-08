#include <stdio.h>
# include <stdlib.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int tmp;

	i = 0;
	if (tab != NULL)
	{
		while (i < size)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				i = -1;
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int *tab;
	unsigned int size;
	int i;

	size = argc -1;
	tab = malloc (size * sizeof (int));

	i = 0;
	while (i < (size))
	{
		tab[i] = atoi(argv[i + 1]);
	i++;
	}

	sort_int_tab(tab, size - 1);

	i = 0;
	while(tab[i])
	{
		printf("%i\n", tab[i]);
		i++;
	}
	return (0);
}