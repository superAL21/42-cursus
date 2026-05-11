#include <unistd.h>

void	hidenp(char *s1, char *s2)
{
	int	i;
	int	j;	
	
	i = 0;
	j = 0;
	while(s2[j] != '\0')
	{
		if(s1[i] == s2[j])
			i++;
		if(s1[i] == '\0')
			break;
		j++;
	}
	if(s1[i] == '\0')
		write(1, "1", 1);
	else
		write(1, "0", 1);
	return;
}

int	main(int argc, char **argv)
{
	if(argc == 3)
		hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
	return(0);
}