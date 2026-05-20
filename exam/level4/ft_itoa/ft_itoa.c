#include <stdlib.h>

int	get_len(long n)
{
	int len = 0;
	if(n <= 0)
		len = 1;
	while(n != 0)
	{
		n = n / 10;
		len++;
	}
	return(len);
}

char *ft_itoa(int nbr)
{
	char *str;
	long	num;
	int	len;

	num = nbr;
	len = get_len(num);
	str = malloc(sizeof(char) * (len + 1));
	if(!str)
		return(NULL);
	str[len] = '\0';
	if(num == 0)
		str[0] = '0';
	if(num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	len--;
	while(num > 0)
	{
		str[len] = (num % 10) + '0';
		len--;
		num = num / 10;
		
	}
	return(str);
}