#include<stdio.h>
#define MAX 10

typedef struct DOB{
    int day;
    int month;
    int year;
}DOB;

typedef struct Citizen{
    int cit_id;
    char name[20];
    char gender[10];
    DOB *dob;
    char state[20];
}Citizen;

typedef struct Stack{
    Citizen citizen[MAX];
    int top;
}Stack;

void initStack(Stack *s){
    s->top = -1;
}

