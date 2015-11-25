#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 32

struct exam_result {
	char exam_name[MAXLEN];
	int exam_grade;
};


struct student {
	char name[MAXLEN];
	struct exam_result *exams[MAXLEN];
};

struct student* new_student(char name[])
{
	struct student *s = malloc(sizeof(struct student));

	strcpy(s->name, name);

	for(int i = 0; i < MAXLEN; ++i) 
		s->exams[i] = NULL;

	return s;
}

void add_exam(struct student *s, char name[], int grade)
{
	int i;

	struct exam_result *e = malloc(sizeof(*e));
	strcpy(e->exam_name, name);
	e->exam_grade = grade;

	for(i = 0; s->exams[i] != NULL && i < MAXLEN; ++i);

	if(i < MAXLEN) s->exams[i] = e;
}

void print_student(struct student *s)
{
	printf("Name: %s\n", s->name);

	for(int i = 0; i < MAXLEN; ++i)
		if(s->exams[i] != NULL)
			printf("Klausur: %s, Note: %d\n", s->exams[i]->exam_name, s->exams[i]->exam_grade);
}

int main()
{
	struct student* db[2];

	/* if(NULL == 0) */
 	/* 	printf("%d \n", NULL + 2); */

	db[0] = new_student("Max Mustermann");
	
	add_exam(db[0], "GTI", 4);
	add_exam(db[0], "SyA", 3);

	db[1] = new_student("Sepp Wurz");
	add_exam(db[1], "GTI", 1);
	add_exam(db[1], "SyA", 1);
	add_exam(db[1], "ThI", 2);

	for(int i = 0; i < 2; ++i)
		print_student(db[i]);

	return 0;
}

/* Local Variables: */
/* compile-command: "make ex02" */
/* End: */
