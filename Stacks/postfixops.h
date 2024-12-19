int stackPrecPost(char symbol){
    switch(symbol){
        case '+' :
        case '-' :
            return 2;
        case '*' :
        case '/' :
            return 4;
        case '^' : 
            return 5;
        case '(' :
            return 0;
        case '#' : 
            return -1;
        default :
            return 8;
    }
}

int inputPrecPost(char symbol){
    switch(symbol){
        case '+' :
        case '-' :
            return 1;
        case '*' :
        case '/' :
            return 3;
        case '^' : 
            return 6;
        case '(' :
            return 9;
        case ')' : 
            return 0;
        default :
            return 7;
    }
}

void infix_to_postfix(Stack *ps, char infix[], int n, char postfix[]){
    int i;
    int j=0;
    char symbol;
    ps->tos = 0;
    ps->arr[ps->tos] ='#';

    for(i =0; i<n; i++){
        symbol = infix[i];

        while(stackPrecPost(ps->arr[ps->tos]) > inputPrecPost(symbol)){
            postfix[j] = pop(ps);
            j++;
        }
        if(stackPrecPost(ps->arr[ps->tos]) != inputPrecPost(symbol)){
            push(ps, symbol);
        }
        else   
            ps->tos--;
    }

    while(ps->arr[ps->tos] != '#'){
        postfix[j++] = pop(ps);
    }
    
    postfix[j] = '\0';
}
