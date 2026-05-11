#include <stdlib.h>

int	*ft_range(int	start, int end)
{
	int	*range;
	int	i;
	int	size;

	if(start <= end)
		size = end - start + 1;
	else
		size = start - end + 1;
	
	range = malloc(sizeof(int) * size);
	if(!range)
		return(NULL);
	i = 0;
	while(i < size)
	{
		range[i] = start;
		if(start <= end)
			start++;
		else
			start--;
		i++;
	}
	return(range);
}