#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element *list;
struct element {
	int value;
	list next;
};

list cons(int, list);
void printList(list);

int sum(list l)
{
	int sum = 0;

	while(l != NULL) {
		sum = sum + l->value;
		l = l->next;
	}

	return sum;
}

int sum_rec(list l)
{
	if(l == NULL) return 0;

	/* nicht notwendig */
	/* if(l->next == NULL) return l->value; */

	return l->value + sum_rec(l->next);
}

void rmEvens(list *lp)
{
	if(lp == NULL) return;

	while(*lp != NULL) {
		if((*lp)->value % 2 == 0) {
			list tmp = *lp;
			*lp = (*lp)->next;
			free(tmp);
		} else {
			lp = &(*lp)->next;
		}

	}
}

void rmEvens_rec(list *lp)
{
	if(lp == NULL) return;

	/* Basisfall der Rekursion */
	if(*lp == NULL) return;

	rmEvens_rec(&(*lp)->next);

	if((*lp)->value % 2 == 0) {
		list tmp = *lp;
		*lp = (*lp)->next;
		free(tmp);
	} 
		
}

int main()
{
	list l = cons(8, cons(1, cons(2, cons(3, cons(7, cons(2, NULL))))));

	printList(l);

	/* list l = NULL; */

	rmEvens_rec(&l);

	printList(l);

	return 0;
}























list cons(int n, list next)
{
	list l = malloc(sizeof(*l));
	l->value = n;
	l->next = next;
	return l;
}

void printList(list l)
{
	printf("[");
	while(l){
		printf("%d", l->value);
		if(l->next) printf(", ");
		l = l->next;
	}
	printf("]\n");
}


/* Local Variables: */
/* compile-command: "make ex01" */
/* End: */
