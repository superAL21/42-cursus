char	*ft_strrev(char *str)
{
	char	*start;
	char 	*end;
	char 	temp;

	start = str;
	end = str;
	if(!str || !*str)
		return(str);
	while(*end)
		end++;
	end--;
	while(start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	return(str);
}