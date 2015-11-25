#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 32

typedef struct exam_result {
	char exam_name[MAXLEN];
	int exam_grade;
} exam_result;

typedef struct student {
	char name[MAXLEN];
	exam_result *exams[MAXLEN];
} student;

student* new_student(char name[])
{
	student* s = malloc(sizeof(*s));

	//	s->name = (*s).name

	strcpy(s->name, name);

	for(int i = 0; i < MAXLEN; ++i)
		s->exams[i] = NULL;

	return s;
}

void add_exam(student* s, char name[], int grade)
{
	for(int i = 0; i < MAXLEN; i++) {
		if(s->exams[i] == NULL){
			s->exams[i] = malloc(sizeof(exam_result));
			strcpy(s->exams[i]->exam_name, name);
			s->exams[i]->exam_grade = grade;
			break;
		}
	}
}

void print_student(student s)
{
	printf("Name: %s\n", s.name);

	for(int i = 0; i < MAXLEN; ++i){
		if(s.exams[i] != NULL)
			printf("Fach: %s: Note %d\n", s.exams[i]->exam_name, s.exams[i]->exam_grade);
	}
}

int main()
{
	student* db[2];

	db[0] = new_student("Max Mustermann");
	
	add_exam(db[0], "GTI", 4);
	add_exam(db[0], "SyA", 3);

	db[1] = new_student("Sepp Wurz");
	add_exam(db[1], "GTI", 1);
	add_exam(db[1], "SyA", 1);
	add_exam(db[1], "ThI", 2);

	for(int i = 0; i < 2; ++i)
		print_student(*db[i]);

	return 0;
}

/* Local Variables: */
/* compile-command: "make ex02" */
/* End: */
