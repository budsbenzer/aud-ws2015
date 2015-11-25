#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 32

struct exam_result {
	char exam_name[MAXLEN];
	int exam_grade;
	struct exam_result *next;
};


struct student {
	char name[MAXLEN];
	struct exam_result *exams;
	struct student *next;
};

struct student* new_student(struct student *l, char name[])
{
	if(l == NULL){
		struct student *s = malloc(sizeof(struct student));
		strcpy(s->name, name);
		s->exams = NULL;
		s->next = NULL;

		return s;
	}


	if(l->next == NULL){
		struct student *s = malloc(sizeof(struct student));

		strcpy(s->name, name);
		s->exams = NULL;

		l->next = s;
		return s;
	} else {
		return new_student(l->next, name);
	}
}

/* void add_exam(struct student *s, char name[], int grade) */
/* { */
/* 	int i; */

/* 	struct exam_result *e = malloc(sizeof(*e)); */
/* 	strcpy(e->exam_name, name); */
/* 	e->exam_grade = grade; */

/* 		for(i = 0; s->exams[i] != NULL && i < MAXLEN; ++i); */

/* 		if(i < MAXLEN) s->exams[i] = e; */
/* 	} */

	void print_student(struct student *s)
	{
		if(s == NULL) return;
		
		printf("Name: %s\n", s->name);
		print_student(s->next);

		/* for(int i = 0; i < MAXLEN; ++i) */
		/* 	if(s->exams[i] != NULL) */
		/* 		printf("Klausur: %s, Note: %d\n", s->exams[i]->exam_name, s->exams[i]->exam_grade); */
	}

int main()
{
	struct student* s = NULL;

	s = new_student(s, "Max");

	new_student(s, "Sepp");

	/* if(NULL == 0) */
	/* 	printf("%d \n", NULL + 2); */

	
	/* add_exam(db[0], "GTI", 4); */
	/* add_exam(db[0], "SyA", 3); */

	/* db[1] = new_student("Sepp Wurz"); */
	/* add_exam(db[1], "GTI", 1); */
	/* add_exam(db[1], "SyA", 1); */
	/* add_exam(db[1], "ThI", 2); */

	/* for(int i = 0; i < 2; ++i) */
	print_student(s);

	return 0;
}

/* Local Variables: */
/* compile-command: "make ex02b" */
/* End: */
