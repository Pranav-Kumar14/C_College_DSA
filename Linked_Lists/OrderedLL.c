#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode(){
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if(x==NULL){
        printf("Out of memory!");
        exit(0);
    }
    return x;
}

void freenode(NODE x){
    free(x);
}

NODE insert(int item, NODE first){
    NODE temp;
    NODE cur, prev;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if(first==NULL){
        return temp;
    }
    if(item<first->info){
        temp->link = first;
        return temp;
    }
    prev = NULL;
    cur = first;
    while(cur!=NULL && item>cur->info){
        prev=cur;
        cur=cur->link;
    }
    prev->link=temp;
    temp->link=cur;
    return first;    
}

NODE delete_front(NODE first){
    NODE temp;
    if(first==NULL){
        printf("The list is empty cannot delete!\n");
        return first;
    }
    temp = first;
    temp = temp->link;
    printf("%d deleted!\n", first->info);
    freenode(first);
    return temp;
}

NODE delete_rear(NODE first){
    NODE cur;
    NODE prev;
    if(first==NULL){
        printf("List is empty!\n");
        return first;
    }
    if(first->link == NULL){
        printf("%d deleted\n", first->info);
        freenode(first);
        return NULL;
    }
    prev = NULL;
    cur = first;
    while(cur->link!=NULL){
        prev = cur;
        cur = cur->link;
    }
    printf("%d deleted\n", cur->info);
    freenode(cur);
    prev->link = NULL;
    return first;
}

void display(NODE first){
    NODE temp;
    if(first == NULL){
        printf("List is empty!\n");
        return;
    }
    printf("The singly linked list -> \n");
    temp = first;
    while(temp!= NULL){
        printf("%d\t", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

void main(){
    NODE first = NULL;
    int choice, item;

    for(;;){
        printf("1.INSERT  2.DELETE FRONT  3.DELETE REAR  4.DISPLAY   5.QUIT\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);

        switch(choice){
            case 1 :
                printf("Enter the item to be inserted : \n");
                scanf("%d", &item);
                first = insert(item, first);
                break;
            case 2 :
                first = delete_front(first);
                break;
            case 3 : 
                first = delete_rear(first);
                break;
            case 4 :
                display(first);
                break;
            case 5 :
                printf("Exiting!");
                exit(0);
            default : 
                printf("Invalid choice!\n");
                break;
        }
    }
}