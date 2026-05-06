#include <unistd.h>

void	search_replace(char *str, char search, char replace)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == search)
			str[i] = replace;
		write(1, &str[i], 1);
		i++;
	}
	return;
}

int	main(int argc, char **argv)
{
	if(argc == 4)
	{
		if(argv[2][1] == '\0' && argv[3][1] == '\0')
			search_replace(argv[1], argv[2][0], argv[3][0]);
	}
	write(1, "\n", 1);
	return (0);
	
}