#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*res;
	int	size;
	int	i = 0;

	if(start > end)
		size = start - end + 1;
	else
		size = end - start + 1;
	res = malloc(sizeof(int) * size);
	if(!res)
		return(NULL);
	while(i < size)
	{
		{
			res[i] = start;
			if(start <= end)
				start++;
			else
				start--;
			i++;
		}
	}
	return(res);
}