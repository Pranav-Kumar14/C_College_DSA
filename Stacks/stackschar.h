#define SIZE 10

typedef struct Stack{
    char arr[SIZE];
    int tos;
}Stack;

int isEmpty(Stack *ps){
    if(ps->tos == -1)
        return 1;
    return 0;
}

int isFull(Stack *ps){
    if(ps->tos == SIZE-1)
        return 1;
    return 0;
}

void push(Stack *ps, char x){
    if(isFull(ps) == 0){
        ps->tos++;
        ps->arr[ps->tos] = x;
    }
    else
        printf("Stack Overflow!\n");
}

char pop(Stack *ps){
    if(isEmpty(ps) == 0){
        return (ps->arr[ps->tos--]);
    }
    else{
        printf("Stack Underflow!\n");
        return 0;
    }
}

void display(Stack *ps){
    for(int i=0; i<= ps->tos; i++){
        printf("%c\n", ps->arr[i]);
    }
    printf("\n");
}
