int stackPrecPre(char symbol){
    switch(symbol){
        case '+' :
        case '-' :
            return 1;
        case '*' :
        case '/' :
            return 3;
        case '^' : 
            return 6;
        case ')' :
            return 0;
        case '#' : 
            return -1;
        default :
            return 8;
    }
}

int inputPrecPre(char symbol){
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
        case ')' : 
            return 9;
        default :
            return 7;
    }
}

void infix_to_prefix(Stack *ps, char infix[], int n, char prefix[]){
    int i;
    int j=0;
    char symbol;
    ps->tos = 0;
    ps->arr[ps->tos] ='#';

    for(i =0; i<n; i++){
        symbol = infix[i];

        while(stackPrecPre(ps->arr[ps->tos]) > inputPrecPre(symbol)){
            prefix[j] = pop(ps);
            j++;
        }
        if(stackPrecPre(ps->arr[ps->tos]) != inputPrecPre(symbol)){
            push(ps, symbol);
        }
        else   
            ps->tos--;
    }

    while(ps->arr[ps->tos] != '#'){
        prefix[j++] = pop(ps);
    }

    prefix[j] = '\0';
}
