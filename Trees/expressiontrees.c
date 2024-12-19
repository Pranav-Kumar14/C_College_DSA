NODE create_tree(char postfix[]){
    NODE temp, st[20]; 
    int i, k;
    char symbol;
    for(i=k=0; (symbol=postfix[i])!='\0'; i++){
        temp=getnode();
        temp->info = symbol;
        temp->llink=temp->rlink=NULL;
        if(isalnum(symbol)) st[k++] = temp;
        else{
            temp->rlink = st[--k];
            temp->llink = st[--k];
            st[k++]= temp;
        }
    }
    return st[--k];
}

float eval(NODE eval){
    float num;
    switch(root->info){
        case '+' : return eval(root->llink)+eval(root->rlink);
        case '-' : return eval(root->llink)-eval(root->rlink);
        case '*' : return eval(root->llink)*eval(root->rlink);
        case '/' : return eval(root->llink)/eval(root->rlink);
        default:
            if(isalpha(root->info)){
                printf("%c = ", root->info);
                scanf("%f", &num);
                return num;
            }
            else
                return root->info-'0';
    }
}