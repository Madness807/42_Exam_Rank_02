#include <stdlib.h>
#include <stdio.h>

int		absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int		get_len(int nbr)
{
	int	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char *res;
	int len = 0;

	len = get_len(nbr);
	res = malloc((len +1) * sizeof (char));
	res[len] = '\0';

	if (nbr < 0)
		res[0] = '-';
	else if (nbr == 0)
		res[0] = '0';
	
	while (nbr != 0)
	{
		res[len - 1] = absolute_value(nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	printf("%s\n", ft_itoa(atoi(argv[1])));
    return (0);
}