int	max(int *tab, unsigned int len)
{
	int	max;
	int	i;

	i = 0;
	max = tab[0];
	while(len > 0)
	{
		if(tab[i] > max)
			max = tab[i];
		i++;
	}
	return(max);
}