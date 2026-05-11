#include <unistd.h>

void	expand_str(char *str)
{
	int	i;
	int	first_word;

	first_word = 1;
	i = 0;
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	while(str[i] != '\0')
	{
		if(str[i] != ' ' && str[i] != '\t')
		{
			if(!first_word && (str[i - 1] == ' ' || str[i - 1] == '\t'))
				write(1, "   ", 3);
			write(1, &str[i], 1);
			first_word = 0;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if(argc == 2)
		expand_str(argv[1]);
	write(1, "\n", 1);
	return(0);
}