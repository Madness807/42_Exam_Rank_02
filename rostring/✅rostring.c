#include <unistd.h>

int main (int argc , char **argv)
{
	int i = 0;
	int j;
	char *str = argv[1];

	if (argc >= 2)
	{
			while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			{
				i++;
			}
			j = i; 
			while (str[i])
			{
				while (str[i] && (str[i] != ' ' && str[i] != '\t'))
				{
					i++;
				}
				while (str[i] && (str[i] == ' ' || str[i] == '\t'))
				{
					i++;
				}
				while (str[i] && (str[i] != ' ' && str[i] != '\t') && (str[i -1] == ' ' || str[i - 1] == '\t'))
				{
					while (str[i] && (str[i] != ' ' && str[i] != '\t'))
					{
						write (1, &str[i], 1);
						i++;
					}
					write (1, " ", 1);
					i++;
				}
			}
			while (str[j] && (str[j] != ' ' && str[j] != '\t'))
			{
				write (1, &str[j], 1);
				j++;
			}
	}
	write (1, "\n", 1);
}