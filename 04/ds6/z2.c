#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int n, m;
	unsigned int secret;

	printf("n eingeben: ");
	scanf("%u", &n);

	secret = rand() % n + 1;

	do {
		printf("Rate eine Zahl! ");
		scanf("%u", &m);

		if(m > secret)
			printf("Zu hoch geraten!\n");
		if(m < secret)
			printf("Zu tief geraten!\n");
	} while(m != secret);

	printf("Gewonnen!\n");

	return 0;
}


/* Local Variables: */
/* compile-command: "make z2" */
/* End: */
