#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
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
    double s[20];
    double res = 0;
    double op1;
    double op2;
    int top;
    int i;
    char postfix[20];
    char symbol;

    printf("Enter the postfix expression : \n");
    scanf("%s", postfix);

    top=-1;
    for(i=0; i<strlen(postfix); i++){
        symbol = postfix[i];
        if(digit(symbol) == 1){
            s[++top] = symbol -'0';
        }
        else{
            op2 = s[top--];
            op1 = s[top--];
            res = compute(symbol, op1, op2);
            s[++top] = res;
        }
    }
    res = s[top--];

    printf("The result is : %f", res);
}