#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *tree;
struct node {
	int value;
	tree left, right;
};

void f(int k, int n)
{
	int m;

	for (m = n - (n % k); m >= 0; m = m - k)
		printf("%d ", m);
}

int evenSum(tree t)
{
	if (t == NULL) return 0;

	return t->value + oddSum(t->left) + oddSum(t->right);
}

int oddSum(tree t)
{
	if (t == NULL) return 0;

	return evenSum(t->left) + evenSum(t->right);
}

void dechain(tree *t)
{
	tree tmp;

	if(t == NULL || *t == NULL) return;

	if((*t)->left != NULL && (*t)->right == NULL) {
		tmp = *t;
		*t = (*t)->left;
		free(tmp); 
		dechain(t);
	} else if((*t)->left == NULL && (*t)->right != NULL) {
		tmp = *t;
		*t = (*t)->right;
		free(tmp); 
		dechain(t);
	} else {
		dechain(&(*t)->left);
		dechain(&(*t)->right);
	}
}

int main()
{

	return 0;
}

/* Local Variables: */
/* compile-command: "make ex03" */
/* End: */
