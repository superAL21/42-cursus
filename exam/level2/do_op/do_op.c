#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	do_op(int a, char ope, int b)
{
	int	result;

	result = 0;
	if (ope == '-')
		result = a - b;
	else if (ope == '+')
		result = a + b;
	else if (ope == '*')
		result = a * b;
	else if (ope == '/')
		result = a / b;
	else if (ope == '%')
		result = a % b;
	return(result);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int result;

	
	if(argc == 4)
	{
		a = atoi(argv[1]);
		b = atoi(argv[3]);
		result = do_op(a, argv[2][0], b);
		printf("%i", result);
	}
	printf("\n");
	return(0);
}