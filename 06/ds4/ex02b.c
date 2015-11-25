#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 32


typedef struct exam_result exam_result;
struct exam_result {
	char exam_name[MAXLEN];
	int exam_grade;
	exam_result *next;
};

typedef struct student student;
struct student {
	char name[MAXLEN];
	exam_result *exams;
	student *next;
};

student* new_student(student *l, char name[])
{
	student* s = malloc(sizeof(*s));

	//	s->name = (*s).name

	strcpy(s->name, name);

	for(int i = 0; i < MAXLEN; ++i)
		s->exams = NULL;

	s->next = l;

	return s;
}

void add_exam(student* s, char name[], int grade)
{
	/* for(int i = 0; i < MAXLEN; i++) { */
	/* 	if(s->exams[i] == NULL){ */
	/* 		s->exams[i] = malloc(sizeof(exam_result)); */
	/* 		strcpy(s->exams[i]->exam_name, name); */
	/* 		s->exams[i]->exam_grade = grade; */
	/* 		break; */
	/* 	} */
	/* } */
}

void print_student(student* s)
{
	if(s == NULL) return;

	printf("Name: %s\n", s->name);
	
	print_student(s->next);

	/* for(int i = 0; i < MAXLEN; ++i){ */
	/* 	if(s.exams[i] != NULL) */
	/* 		printf("Fach: %s: Note %d\n", s.exams[i]->exam_name, s.exams[i]->exam_grade); */
	/* } */
}

int main()
{
	student* student = NULL;

	student = new_student(student, "Max Mustermann");
	
	/* add_exam(db[0], "GTI", 4); */
	/* add_exam(db[0], "SyA", 3); */

	student = new_student(student, "Sepp Wurz");
	/* add_exam(db[1], "GTI", 1); */
	/* add_exam(db[1], "SyA", 1); */
	/* add_exam(db[1], "ThI", 2); */

	/* for(int i = 0; i < 2; ++i) */
	print_student(student);

	return 0;
}

/* Local Variables: */
/* compile-command: "make ex02b" */
/* End: */
