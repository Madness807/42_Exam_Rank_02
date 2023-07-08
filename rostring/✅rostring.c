#include <unistd.h>

int main (int ac , char **av)
{
	int i = 0;
	int j;
	char *str = av[1];

	if (ac >= 2)
	{
			while (str[1][i] && (str[1][i] == ' ' || str[1][i] == '\t')) // search for is_space and move the position.
			{
				i++;
			}
			j = i; // this is the postion of starting of the word.
			while (str[1][i])
			{
				while (str[1][i] && (str[1][i] != ' ' && str[1][i] != '\t')) // find the next word.
				{
					i++;
				}
				while (str[1][i] && (str[1][i] == ' ' || str[1][i] == '\t')) // find the next word.
				{
					i++;
				}
				while (str[1][i] && (str[1][i] != ' ' && str[1][i] != '\t') && (str[1][i -1] == ' ' || str[1][i - 1] == '\t')) // print the word till it reaches last.
				{
					while (str[1][i] && (str[1][i] != ' ' && str[1][i] != '\t'))
					{
						write (1, &str[1][i], 1);
						i++;
					}
					write (1, " ", 1);
					i++;
				}
			}
			while (str[1][j] && (str[1][j] != ' ' && str[1][j] != '\t')) // print the first word now.
			{
				write (1, &str[1][j], 1);
				j++;
			}
	}
	write (1, "\n", 1);
}