#include <stdio.h>


int fak(int n)
{
	if(n == 0)
		return 1;
	/* else if (n == 2) */
	/* 	return 2; */
	else
		return n * fak(n-1);
}

int main()
{
	int n;

	int ret = 1;
	printf("Zahl eingeben: ");
	scanf("%d", &n);

	while(n > 0){
		ret = n * ret;
		n--;
	}
		


	printf("Fakultaet ist %d\n", ret);
}


/* Local Variables: */
/* compile-command: "make ex03" */
/* End: */
