#include <unistd.h>

void	wdmatch(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(s1[i] != '\0' && s2[j] != '\0')
	{
		if(s1[i] == s2[j])
			i++;
		j++;
	}
	if(s1[i] == '\0')
	{
		i = 0;
		while(s1[i] != '\0')
		{
			write(1, &s1[i], 1);
			i++;
		}
	}
	return;
}

int	main(int argc, char **argv)
{
	if(argc == 3)
	{
		wdmatch(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return(0);
}