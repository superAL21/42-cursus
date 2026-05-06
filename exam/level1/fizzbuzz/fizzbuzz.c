#include <unistd.h>

void	ft_putnmbr(int n)
{
	char *decimal;

	decimal = "0123456789";
	if(n > 9)
	{	
		ft_putnmbr(n / 10);
	}
	write(1, &decimal[n % 10], 1);
}
void	fizzbuzz(void)
{
	int	n;
	
	n = 1;
	while(n <= 100)
	{
		if(n % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if(n % 3 == 0)
			write(1, "fizz", 4);
		else if(n % 5 == 0)
			write(1, "buzz", 4);
		else 
			ft_putnmbr(n);
		write(1, "\n", 1);
		n++;
	}
}

int	main(void)
{
	fizzbuzz();
	return(0);
}