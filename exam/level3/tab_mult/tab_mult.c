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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return;
}
void	ft_putnmbr(int	num)
{
	char	*numbers;

	numbers = "0123456789";
	if(num > 9)
	{
		ft_putnmbr(num / 10);
	}
	write(1, &numbers[num % 10], 1);
	return;
}
void	tab_mult(int num)
{
	int	i;
	i = 1;
	while(i <= 9)
	{
		ft_putnmbr(i);
		ft_putstr(" x ");
		ft_putnmbr(num);
		ft_putstr(" = ");
		ft_putnmbr(i * num);
		write(1, "\n", 1);
		i++;
	}
	return;
}
int main(int argc, char **argv)
{
	if(argc == 2)
		tab_mult(ft_atoi(argv[1]));
	else
		write(1, "\n", 1);
	return(0);
}