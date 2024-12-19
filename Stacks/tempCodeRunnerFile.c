#include<stdio.h>
#include<math.h>
#include<string.h>
#include "stacksop.h"

double compute(char symbol, double op1, double op2){
    switch(symbol){
        case '+' : return op1+op2;
        case '-' : return op1-op2;
        case '*' : return op1*op2;
        case '/' : return op1/op2;
        case '^' : return pow(op1, op2);
    }
}

int digit(char symbol){
    switch(symbol){
        case '+' :
        case '-' :
        case '*' :
        case '/' :
        case '^' :
            return 0;
        default : 
            return 1;
    }
}

//evaluate a postfix expression

void main(){
    Stack s;
    s.tos = -1;
    double op1;
    double op2;
    double res = 0;
    char postfix[20];
    char symbol;

    printf("Enter the postfix expression : \n");
    scanf("%s", postfix);

    for(int i=0; i<strlen(postfix); i++){
        symbol = postfix[i];
        if(digit(symbol) == 1){
            push(&s, symbol -'0');
        }
        else{
            op2 = pop(&s);
            op1 = pop(&s);
            res = compute(symbol, op1, op2);
            push(&s, res);
        }
    }
    res = s.arr[s.tos--];

    printf("The result is : %f", res);
}

