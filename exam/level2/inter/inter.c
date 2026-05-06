#include <unistd.h>

void	ft_inter(char *s1, char *s2)
{
	int	j;
	int	i;
	int	used[256] = {0};

	i = 0;
	while(s1[i] != '\0')
	{
		j = 0;
		if(used[(unsigned char)s1[i]] == 0)
		{
			while(s2[j] != '\0')
			{
				if(s1[i] == s2[j])
				{
					write(1, &s1[i], 1);
					used[(unsigned char)s1[i]] = 1;
					break;
				}
				j++;
			}
		}
		i++;
	}
	return;
}
int	main(int argc, char **argv)
{
	if(argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return(0);
}