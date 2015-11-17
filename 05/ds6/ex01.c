#include <stdio.h>
#include <stdlib.h>


unsigned int fib(unsigned int n)
{
	if(n < 3) return 1;

	return fib(n-1) + fib(n-2);
}

unsigned int G(unsigned int n)
{
	if(n == 0) return 0;

	return n - G(G(n-1));
}

unsigned int M(unsigned int n);

unsigned int F(unsigned int n)
{
	if(n == 0) return 1;

	return n - M(F(n-1));
}


unsigned int M(unsigned int n)
{
	if(n == 0) return 0;

	return n - F(M(n-1));
}



int main()
{
	unsigned int n;

	/* printf("Zahl eingeben: "); */
	/* scanf("%u", &n); */

	for(n = 0; n < 20; n++)
		printf("F(%u) = %u\n", n, F(n));
	return 0;
}


/* Local Variables: */
/* compile-command: "make ex01" */
/* End: */
