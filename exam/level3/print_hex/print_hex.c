#include <unistd.h>

int	ft_atoi(char *str)
{
	int	res;
	int	i;
	
	i = 0;
	res = 0;
	while(str[i] != '\0')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return(res);
}

void	print_hex(int	num)
{
	char *hex;

	hex = "0123456789abcdefgh";
	if(num > 16)
		print_hex(num / 16);
	write(1, &hex[num % 16], 1);
	return;
}
int	main(int argc, char **argv)
{
	if(argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
}