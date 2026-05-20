unsigned char	 reverse_bits(unsigned char octet)
{
	unsigned char	result;
	int	i;
	
	result = 0;
	i = 8;
	while(i > 0)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
		i--;
	}
	return(result);
}
