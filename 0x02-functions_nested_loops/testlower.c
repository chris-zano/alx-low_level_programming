#include <stdio.h>

int main(void)
{
	char c = 'a';
	char b = 'A';

	if (c > b)
	{
		printf("Lower bigger than upper, %d-lower\t%d-upper\n", c, b);
	}else
	{
		printf("Upper bigger than lower, %d-upper\t%d-lower\n", b, c);
	}
	return (1);
}
