#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')

		i++;
	return(i);
}
char *ft_strdup(char *src)
{
	char	*new;
	int		i;
	
	i = 0;
	new = malloc((sizeof(char) * ft_strlen(src)) + 1);
	while(src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return(new);
}