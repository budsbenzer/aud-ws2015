#include <stdio.h>

int main()
{
	char name[100];

	printf("Namen eingeben: ");
	scanf("%s", name);

	printf("Hallo %s!\n", name);

	return 0;
}


/* Local Variables: */
/* compile-command: "make ex02a" */
/* End: */
