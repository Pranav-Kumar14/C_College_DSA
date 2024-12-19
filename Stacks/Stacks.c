#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stackschar.h"
#include "postfixops.h"
#include "prefixops.h"

int main(){
    Stack s;
    char infix1[30], infix2[30], postfix[30], prefix[30];
    printf("Enter the valid infix expression for postfix : ");
    scanf("%s", infix1);

    int n = strlen(infix1);

    infix_to_postfix(&s, infix1, n, postfix);

    printf("The postfix expression is : %s\n", postfix);

    printf("Enter the valid infix expression for prefix : ");
    scanf("%s", infix2);

    strrev(infix2);

    int m = strlen(infix2);

    infix_to_prefix(&s, infix2, m, prefix);
    strrev(prefix);

    printf("The prefix expression is : %s\n", prefix);
    
    return 0;
}

