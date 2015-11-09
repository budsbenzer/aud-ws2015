#include <stdio.h>

#define LEN 1000000

int main()
{
	int s[LEN];

	int i;

	for(i = 0; i < LEN; ++i) 
		s[i] = 1;

	for(i = 2; i < LEN; ++i){
		if(s[i] == 1){
			int j = 1;
			printf("%d\n", i);
			while(i * j < LEN){
				s[i*j] = 0;
				++j;
			}
				
		}
	}
}


/* Local Variables: */
/* compile-command: "make ex02c" */
/* End: */
