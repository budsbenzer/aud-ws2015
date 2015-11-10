#include <stdio.h>

int main()
{
	int n, i, j;

	printf("Eingabe von n: ");
	scanf("%d", &n);

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j)
			printf("%d\t", i*j);
		/* oder printf("%-5d", i*j); oder einfach "%d" */
		printf("\n");
	}

}


/* Local Variables: */
/* compile-command: "make ex02b" */
/* End: */
