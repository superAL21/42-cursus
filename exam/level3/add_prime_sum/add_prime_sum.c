#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while(str[i] != '\0')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return(res);
}

void	ft_putnumbr(int num)
{
	char *numbers;

	numbers = "0123456789";
	if(num > 9)
		ft_putnumbr(num / 10);
	write(1, &numbers[num % 10], 1);
	return;
}
int	is_prime(int num)
{
	int	n;

	n = 2;
	if(num <= 1)
		return(0);
	while(n * n <= num)
	{
		if(num % n == 0 )	
			return(0);
		n++;
	}
	return(1);
}
void	add_prime_sum(int n)
{
	int i;
	int	sum;

	sum = 0;
	i = 2;
	while(i <= n)
	{
		if(is_prime(i))
			sum = sum + i;
		i++;
	}
	ft_putnumbr(sum);
}
int	main(int argc, char **argv)
{
	int	number;

	if(argc == 2)
	{
		number = ft_atoi(argv[1]);
		if(number > 0)
			add_prime_sum(number);
		else
			write(1, "0", 1);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return(0);
}
