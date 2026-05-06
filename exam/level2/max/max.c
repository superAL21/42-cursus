int	max(int *tab, unsigned int len)
{
	int	i;
	int	max;

	if(!tab || len == 0)
		return(0);
	max = tab[0];
	i = 0;
	while(len--)
	{
		if(tab[i] > max)
			max = tab[i];
		i++;
	}
	return(max);
}