#include <unistd.h>

void	ft_putchar_int(char str, int n)
{
	while(n > 0)
	{
		write(1, &str, 1);
		n--;
	}
	return;
}

void	repeat_alpha(char	*str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			ft_putchar_int(str[i], (int)(str[i] - 'a' + 1));
		else if(str[i] >= 'A' && str[i] <= 'Z')
			ft_putchar_int(str[i], (int)(str[i] - 'A' + 1));
		else
			write(1, &str[i], 1);
		i++;
	}
	return;
}

int	main(int argc, char **argv)
{
	if(argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return(0);
}