void push(char item[], int *top, char s[][20]){
    *top = *top +1;
    strcpy(s[*top], item);
}

char *pop(int *top, char s[][20]){
    char *item;
    item = s[*top];
    *top = *top - 1;
    return item;
}

void post_inf(char postfix[], char infix[]){
    char s[20][20];
    int top;
    top = -1;
    char temp[2];
    char symbol;
    char *op1;
    char *op2;
    for(int i=0; i< strlen(postfix); i++){
        symbol = postfix[i];
        temp[0] = symbol;
        temp[1] = '\0';
        switch(symbol){
            case '+' :
            case '-' :
            case '*' :
            case '/' :
            case '^' :
                op2 = pop(&top, s);
                op1 = pop(&top, s);
                strcpy(infix, "(");
                strcat(infix, op1);
                strcat(infix, temp);
                strcat(infix, op2);
                strcat(infix, ")");
                push(infix, &top, s);
                break;
            default :
                push(temp, &top, s);
        }
    }
}

void post_pre(char postfix[], char prefix[]){
    char s[20][20];
    int top = -1;
    char temp[2];
    char symbol;
    char *op1;
    char *op2;
    for(int i=0; i< strlen(postfix); i++){
        symbol = postfix[i];
        temp[0] = symbol;
        temp[1] = '\0';
        switch(symbol){
            case '+' :
            case '-' :
            case '*' :
            case '/' :
            case '^' :
                op2 = pop(&top, s);
                op1 = pop(&top, s);
                strcpy(prefix, temp);
                strcat(prefix, op1);
                strcat(prefix, op2);
                push(prefix, &top, s);
                break;
            default :
                push(temp, &top, s);
        }
    }
}

void pre_inf(char prefix[], char infix[]){
    char s[20][20];
    int top = -1;
    char temp[2];
    char symbol;
    char *op1;
    char *op2;
    strrev(prefix);
    for(int i=0; i< strlen(prefix); i++){
        symbol = prefix[i];
        temp[0] = symbol;
        temp[1] = '\0';
        switch(symbol){
            case '+' :
            case '-' :
            case '*' :
            case '/' :
            case '^' :
                op1 = pop(&top, s);
                op2 = pop(&top, s);
                strcpy(infix, "(");
                strcat(infix, op1);
                strcat(infix, temp);
                strcat(infix, op2);
                strcat(infix, ")");
                push(infix, &top, s);
                break;
            default :
                push(temp, &top, s);
        }
    }
}

void pre_post(char prefix[], char postfix[]){
    char s[20][20];
    int top = -1;
    char temp[2];
    char symbol;
    char *op1;
    char *op2;
    strrev(prefix);
    for(int i=0; i< strlen(prefix); i++){
        symbol = prefix[i];
        temp[0] = symbol;
        temp[1] = '\0';
        switch(symbol){
            case '+' :
            case '-' :
            case '*' :
            case '/' :
            case '^' :
                op1 = pop(&top, s);
                op2 = pop(&top, s);
                strcpy(postfix, temp);
                strcat(postfix, op1);
                strcat(postfix, op2);
                push(postfix, &top, s);
                break;
            default :
                push(temp, &top, s);
        }
    }
}





