int	get_value(char c)
{
	if(c >= '0' && c <= '9')
		return(c - '0');
	if(c >= 'a' && c <= 'z')
		return(c - 'a' + 10);
	if(c >= 'A' && c <= 'Z')
		return(c - 'A' + 10);
	return(-1);
}
int	ft_atoi_base(const char *str, int str_base)
{
	int	res;
	int	i;
	int	sign;
	int	value;

	i = 0;
	sign = 1;
	res = 0;
	if(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sign = -1;
		i++;
	}
	while(str[i] != '\0')
	{
		value = get_value(str[i]);
		if(value == -1 || value >= str_base)
			break;
		res = (res * str_base) + value;
		i++;
	}
	return(res * sign);
}
