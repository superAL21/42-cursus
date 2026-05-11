#include <unistd.h>

void	str_capitalizer(char *str)
{
	int	i;

	i = 0;
	
	while(str[i] != '\0')
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		if((i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t') 
		&& (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		write(1, &str[i], 1);
		i++;
	}
	return;
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if(argc < 2)
		write(1, "\n", 1);
	else
	{
		i = 1;
		while(i < argc)
		{
			str_capitalizer(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return(0);
}