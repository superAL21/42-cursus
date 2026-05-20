#include <unistd.h>

void	rostring(char *s)
{
	int i = 0;
	int	first_word_start;
	int	first_word_end;

	while(s[i] == ' ' || s[i] == '\t')
		i++;
	first_word_start = i;
	while(s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
		i++;
	first_word_end = i;
	while(s[i] !=  '\0')
	{
		while(s[i] == ' ' || s[i] == '\t')
			i++;
		if(s[i] != '\0')
		{
			while(s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
			{
				write(1, &s[i], 1);
				i++;
			}
			write(1, " ", 1);
		}
	}
	while(first_word_start < first_word_end)
	{
		write(1, &s[first_word_start], 1);
		first_word_start++;
	}
}

int	main(int argc, char **argv)
{
	if(argc >= 2)
	{	
		if(argv[1][0] != '\0')
			rostring(argv[1]);
	}
	write(1, "\n", 1);
	return(0);
}