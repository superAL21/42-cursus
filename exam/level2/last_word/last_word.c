#include <unistd.h>

void	last_word(char *str)
{
	int	i;

	while(str[i] != '\0')
		i++;
	i--;
	while(i > 0 && (str[i] == ' ' || str[i] == '\t'))
		i--;
	while(i > 0 && (str[i] != ' ' && str[i] != '\t') )
		i--;
	i++;
	while(str[i] && str[i] != ' ' && str[i] != '\t')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if(argc==2)
		last_word(argv[1]);
	write(1, "\n", 1);
}