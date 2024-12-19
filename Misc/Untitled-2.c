#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char c[10][50];
    int *m;
}Marks;

typedef struct{
    char *name;
    int reg_no;
    Marks *marks;
}Student;

void read(Student *s, int n){
    s->marks = (Marks*)malloc(sizeof(Marks));
    s->marks->m = (int *)malloc(n * sizeof(int));
    s->name = (char*)malloc(20*(sizeof(char)));

    printf("Student name : ");
    scanf("%s", s->name);
    printf("Registration number : ");
    scanf("%d", &s->reg_no);
    for(int i=0; i<n; i++){
        printf("Subject : ");
        scanf("%s", s->marks->c[i]);
        printf("Marks : \n");
        scanf("%d", &s->marks->m[i]);
    }
}

void display(Student *s, int n){
    printf("Student name : %s\n", s->name);
    printf("Registration number : %d\n", s->reg_no);
    for(int i=0; i<n; i++){
        printf("Marks in Subject %s : %d\n", s->marks->c[i], s->marks->m[i]);
    }
}

void main(){
    int m, n;
    printf("Enter the number of students : ");
    scanf("%d", &m);
    printf("Enter the number of subjects : ");
    scanf("%d", &n);
    Student **stu = (Student**)malloc(m * sizeof(Student*));

    for(int i=0; i<m; i++){
        stu[i] = (Student*)malloc(sizeof(Student));
        printf("Enter student %d ->\n", i+1);
        read(stu[i], n);        
    }
    for(int i=0; i<m; i++){
        printf("Details of student %d ->\n", i+1);
        display(stu[i], n);
    }
    free(stu);
}