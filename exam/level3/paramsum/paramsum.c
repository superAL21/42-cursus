#include <unistd.h>

void	ft_putnumbr(int num)
{
	char *numbers;

	numbers = "0123456789";
	if(num > 9)
		ft_putnumbr(num / 10);
	write(1, &numbers[num % 10], 1);
	return;
}

int	main(int argc, char **argv)
{
	(void)argv;
	ft_putnumbr(argc - 1);
	write(1, "\n", 1);
	return(0);
}