#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;
	int	count;

	i = 0;
	while(str[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		i;

	len = ft_strlen(src);
	dup = malloc(len * sizeof(char));
	if(!dup)
		return(NULL);
	i = 0;
	while(src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0'; 
	return(dup);
}