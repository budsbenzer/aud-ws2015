#include <stdio.h>

int main()
{
	int n;
	int i, j;

	printf("n eingeben: ");
	scanf("%i", &n);

	for (i = 1; i <= n; ++i) {
		for(j = 1; j <= n; ++j)
			printf("%-5d", i*j);
		printf("\n");
	}
}


/* Local Variables: */
/* compile-command: "make ex02b" */
/* End: */
