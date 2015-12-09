#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

























int f(list l)
{
	if(l == NULL) return 1;


	while(l->next != NULL){
		if(abs(l->value - l->next->value) > 1) return 0;
		l = l->next;
	}

	return 1;
}



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


void defol(tree *t)
{
	if(*t == NULL) return;
	

	if((*t)->left == NULL && (**t).right == NULL){ // aequivalent.
		free(*t);
		*t = NULL;
		return;
	}

	if((*t)->left != NULL) defol(&(*t)->left);
	if((*t)->right != NULL) defol(&(*t)->right);
}

int main()
{
	tree t = T(5, T(3, NULL, NULL), T(2, NULL, T(7, NULL, NULL)));

	printTree(t);

	defol(&t);

	printTree(t);

	return 0;
}

/* Local Variables: */
/* compile-command: "make ex01" */
/* End: */
