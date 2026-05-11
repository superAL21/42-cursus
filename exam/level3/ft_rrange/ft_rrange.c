#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int size;
	int	*rrange;
	int	i;

	i = 0;
	if(start >= end)
		size = start - end + 1;
	else
		size = end - start + 1;
	rrange = malloc(sizeof(int) * size);
	if(!rrange)
		return(NULL);
	while(i < size)
	{
		rrange[i] = end;
		if(start <= end)
			end--;
		else
			end++;
		i++;
	}
	return(rrange);
}