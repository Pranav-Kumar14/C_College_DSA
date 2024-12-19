#include<stdio.h>
#include<string.h>
#include "stacksconv.h"

void main(){
    char postfix[20];
    char infix[20];
    char prefix[20];
    int choice;

    printf("1.Post to Inf\n2.Post to Pre\n3.Pre to Inf\n4.Pre to Post\nEnter : ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Enter the valid postfix expression : ");
            scanf("%s", postfix);
            post_inf(postfix, infix);
            printf("Infix expression is : %s", infix);
            break;
        case 2:
            printf("Enter the valid postfix expression : ");
            scanf("%s", postfix);
            post_pre(postfix, prefix);
            printf("Prefix expression is : %s", prefix);
            break;
        case 3:
            printf("Enter the valid prefix expression : ");
            scanf("%s", prefix);
            pre_inf(prefix, infix);
            printf("Infix expression is : %s", infix);
            break;
        case 4:
            printf("Enter the valid prefix expression : ");
            scanf("%s", prefix);
            pre_post(prefix, postfix);
            printf("Postfix expression is : %s", postfix);
            break;
        default : 
            printf("Wrong choice man.");
            break;
    }
}