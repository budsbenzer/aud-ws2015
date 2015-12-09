#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node *tree;
struct node {
	int key;
	tree left, right;
};


tree cons(int n, tree l, tree r)
{
	tree t = malloc(sizeof(*t));
	t->key = n;
	t->left = l;
	t->right = r;
	return t;
}

int count(tree t, int n)
{
	if(t == NULL) return 0;

	if(t->key == n)
		return 1 + count(t->left, n) + count(t->right, n);
	else
		return count(t->left, n) + count(t->right, n);
}

tree baz(tree s, tree t)
{
	if(s == NULL) return NULL;

	s->key = count(t, s->key);

	baz(s->left, t);
	baz(s->right, t);

	return s;
}

void printTree(tree t)
{
	if(t == NULL) {
		printf("N");
		return;}
	printf("%d(", t->key);
	printTree(t->left);
	printf(", ");
	printTree(t->right);
	printf(")");
}

int leafprod(tree t)
{
	if(t == NULL) return 1;

	if(t->left == NULL && t->right == NULL)
		return t->key;

	return leafprod(t->left) * leafprod(t->right);
}


int main()
{
	tree s = cons(5, cons(2, NULL, NULL),
				  cons(3, NULL, NULL));

	tree t = cons(5, cons(2, NULL, NULL),
		          cons(2, NULL, NULL));

	printTree(s);
	printf("\n");

	baz(s,t);

	printTree(s);



	return 0;
}

/* Local Variables: */
/* compile-command: "make ex02" */
/* End: */
