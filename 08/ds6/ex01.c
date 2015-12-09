#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *tree;
struct node {
	int key;
	tree left, right;
};


typedef struct element *list;
struct element {
	int value;
	list next;
};





















void printTreeHelper(tree t, int level, unsigned int branches) {
	int i;
	if (level > 0) {
		for (i = 0; i < level - 1; ++i) {
			if (branches & (1 << i)) {
				printf("│ ");
			} else {
				printf("  ");
			}
		}
		if (branches & (1 << i)) {
			printf("├ ");
		} else {
			printf("└ ");
		}
	}
	if (t == NULL) {
		printf("NULL\n");
	} else {
		printf("%i\n", t->key);
		if (t->left || t->right) {
			printTreeHelper(t->left, level + 1, branches | (1 << level));
			printTreeHelper(t->right, level + 1, branches);
		}
	}
}

tree T(int n, tree l, tree r)
{
	tree t = malloc(sizeof(*t));
	t->key = n;
	t->left = l;
	t->right = r;
	return t;
}

void printTree(tree t) {
	printTreeHelper(t, 0, 0);
}

list cons(int n, list l)
{
	list r = malloc(sizeof(*r));
	r->value = n;
	r->next = l;

	return r;
}


int abs(int x)
{
	if (x < 0) return -x;
	return x;
}

int f(list l)
{
	if (l == NULL) return 1;

	while(l->next != NULL) {
		/* if(l->value != l->next->value + 1 */
		/*    && l->value != l->next->value - 1 */
		/*    && l->value != l->next->value) ... oder: */ 
		
		if(abs(l->value - l->next->value) > 1) return 0;

		l = l->next;
	}
	return 1;
}




void defol(tree *t)
{
	if(*t == NULL) return;

	if((**t).left == NULL && (*t)->right == NULL) { // aequivalente schreibweisen
		free(*t);
		*t = NULL;
	} else{
		defol(&(*t)->left);
		defol(&(*t)->right);
	}
}

int main()
{
	tree t = T(1, T(1, T(2, NULL, NULL), NULL), T(1, T(3, NULL, NULL), NULL));

	printTree(t);

	defol(&t);

	printTree(t);
	return 0;
}

/* Local Variables: */
/* compile-command: "make ex01" */
/* End: */
