#include <stdio.h>

void swap(int *x, int *y)
{
	int tmp;
	
	if(*x % 2 == 1) *y = *y +1;
	
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int main()
{
	int x = 4, y = 6;

	printf("x=%d, y=%d\n", x, y);
	swap(&x, &y);
	printf("x=%d, y=%d\n", x, y);	

	return 0;
}


/* Local Variables: */
/* compile-command: "make ex02" */
/* End: */
