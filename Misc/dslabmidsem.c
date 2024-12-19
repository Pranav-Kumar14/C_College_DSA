#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char subject[100];
    int mrks;
}Marks;

typedef struct{
    char *name;
    int reg_no;
    Marks *marks;
}Student;

void read(Student *s){
    s->marks = (Marks*)malloc(sizeof(Marks));
    s->name = (char*)malloc(20*(sizeof(char)));

    printf("Enter student name : ");
    scanf("%s", s->name);
    printf("Enter registration number : ");
    scanf("%d", &s->reg_no);
    printf("Enter subject name : ");
    scanf("%s", s->marks->subject);
    printf("Enter marks : ");
    scanf("%d", &s->marks->mrks);
}

void display(Student *s){
    printf("Student name : %s\n", s->name);
    printf("Registration number : %d\n", s->reg_no);
    printf("Subject name : %s\n", s->marks->subject);
    printf("Marks in subject : %d\n", s->marks->mrks);
}

void main(){
    Student *stu = (Student*)malloc(sizeof(Student));
    read(stu);
    display(stu);
    free(stu);
}