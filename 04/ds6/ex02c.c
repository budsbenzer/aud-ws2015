#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i;

	unsigned int size;

	int *s;

	printf("size eingeben: ");
	scanf("%u", &size);

	s = malloc(sizeof(int) * size);

	for(i = 0; i < size; ++i)
		s[i] = 1;
	
	for(i = 2; i < sqrt(size); ++i) {
		if(s[i] == 1) {
			int j = 1;
			while(i*j < size) {
				s[i*j] = 0;
				++j;
			}
		}
	}

	for(i = 2; i < size; ++i) 
		if(s[i] == 1)
			printf("%d\n", i);


	
}


/* Local Variables: */
/* compile-command: "make ex02c" */
/* End: */
