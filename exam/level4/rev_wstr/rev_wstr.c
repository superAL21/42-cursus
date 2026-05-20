#include <unistd.h>

void	rev_wstr(char *s)
{
	int	i = 0;
	int	j;
	int start;
	int end;

	while(s[i] != '\0')
		i++;
	while(i >= 0)
	{
		while(i >= 0 && (s[i] == '\0' || s[i] == ' ' || s[i] == '\t'))
			i--;
		end = i;
		while(i >= 0 && s[i] != ' ' && s[i] != '\t')
			i--;
		start = i + 1;
		j = start;
		while(j <= end)
		{
			write(1, &s[j], 1);
			j++;
		}
		if(i > 0)
			write(1, " ", 1);
	}
}

int	main(int argc, char **argv)
{
	if(argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
	return(0);
}
