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

//Evaluate a prefix expression

void main(){
    double s[20];
    double res = 0;
    double op1;
    double op2;
    int top;
    int i;
    char prefix[20];
    char symbol;

    printf("Enter the prefix expression : \n");
    scanf("%s", prefix);

    top=-1;
    for(i= strlen(prefix)-1 ; i >=0; i--){
        symbol = prefix[i];
        if(digit(symbol) == 1){
            s[++top] = symbol -'0';
        }
        else{
            op1 = s[top--];
            op2 = s[top--];
            res = compute(symbol, op1, op2);
            s[++top] = res;
        }
    }
    res = s[top--];

    printf("The result is : %f", res);
}

