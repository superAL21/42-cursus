#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	do_op(int a, char  ope, int b)
{
	int	result;
	
	if(ope == '+')
		result = a + b;
	else if (ope == '-')
		result = a - b;
	else if (ope == '*')
		result = a * b;
	else if (ope == '/')
		result = a / b;
	else if (ope == '%')
		result = a % b;
	return(result);
}

int main(int argc, char **argv)
{
	int	a;
	int	b;
	char	ope;
	
	if(argc == 4)
	{
		a = atoi(argv[1]);
		ope = argv[2][0];
		b = atoi(argv[3]);
		printf("%i", do_op(a, ope, b));
	}
	printf("\n");
	return(0);
}	


