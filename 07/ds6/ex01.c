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
	int ret = 0;

	while(l != NULL){
		ret = ret + l->value;
		l = l->next;
	}

	return ret;
}

int sum_rec(list l)
{
	if(l == NULL) return 0;

	return l->value + sum_rec(l->next);
}

void rmEvens(list *lp)
{
	while(*lp != NULL){
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
	if(lp == NULL || *lp == NULL) return;

	if((*lp)->value % 2 == 0) {
		list tmp = *lp;
		*lp = (*lp)->next;
		free(tmp);
	} else {
		lp = &(*lp)->next;
	}

	rmEvens_rec(lp);
}

int main()
{
	list l = cons(8, cons(1, cons(2, cons(2, cons(3, NULL)))));

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
