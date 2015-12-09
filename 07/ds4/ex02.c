#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node *tree;
struct node {
	int key;
	tree left, right;
};

int leafprod(tree t)
{
	if(t == NULL) return 1;

	if(t->left == NULL && t->right == NULL) return t->key;

	return leafprod(t->left) * leafprod(t->right);
}

tree cons(int n, tree l, tree r)
{
	tree t = malloc(sizeof(*t));
	t->key = n;
	t->left = l;
	t->right = r;
	return t;
}


int main()
{
	tree t = cons(5, cons(2, NULL, NULL),
		          cons(3, NULL, NULL));

	printf("%d\n", leafprod(t));

		return 0;
}

/* Local Variables: */
/* compile-command: "make ex02" */
/* End: */
