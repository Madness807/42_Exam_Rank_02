#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int k;
	int first_word;
	char *str;

	if (argc == 2)
	{
		i = 0;
		first_word = 1;
		str = argv[1];
		while (str[i])
			i++;
		while (i >= 0)
		{
			while (i >= 0 && (str[i] != ' ' && str[i] != '\t'))
				i--;
			k = i + 1;
			if (first_word == 0)
				write(1, " ",1);
			while (str[k] && str[k] != ' ' && str[k] != '\t')
			{
				write (1, &str[k], 1);
				k++;
			}
			first_word = 0;
			i--;
		}
	}
	write(1, "\n", 1);
}
