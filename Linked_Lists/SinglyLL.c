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

NODE insert_front(int item, NODE first){
    NODE temp;

    temp = getnode();
    temp->info = item;
    temp->link = first;

    printf("Inserted %d to the front.\n", item);
    return temp;
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

NODE insert_rear(int item, NODE first){
    NODE temp;
    NODE cur;

    temp = getnode();
    temp->info = item;
    temp->link = NULL;

    if(first == NULL){
        return temp;
    }
    cur = first;
    while(cur->link!=NULL){
        cur = cur->link;
    }    
    cur->link = temp;
    printf("Inserted %d to the end.\n", item);
    return first;
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

void search(int key, NODE first){
    NODE cur;
    if(first == NULL){
        printf("List is empty.\n");
        return;
    }
    cur = first;
    while(cur!=NULL){
        if(key==cur->info)
            break;
        cur=cur->link;
    }
    if(cur==NULL){
        printf("%d not found.\n", key);
        return;
    }
    printf("%d found.\n", key);
}

NODE delete_info(int key, NODE first){
    NODE prev, cur;
    if(first == NULL){
        printf("The list is empty!\n");
        return NULL;
    }
    if(key==first->info){
        cur=first;
        first=first->link;
        freenode(cur);
        return first;
    }
    prev = NULL;
    cur = first;
    while(cur!=NULL){
        if(key==cur->info) 
            break;
        prev = cur;
        cur = cur->link;
    }
    if(cur==NULL){
        printf("%d is not in the list\n", key);
        return first;
    }
    prev->link = cur->link;
    freenode(cur);
    return first;
}

NODE delete_pos(int pos, NODE first){
    NODE cur, prev;
    int count;
    if(first == NULL || pos<=0){
        printf("Invalid position or empty list.\n");
        return NULL;
    }
    if(pos==1){
        cur = first;
        first = first->link;
        freenode(cur);
        return first;
    }
    prev = NULL;
    cur = first;
    count = 1;
    while(cur!=NULL){
        if(count==pos)
            break;
        prev=cur;
        cur = cur->link;
        count++;
    }
    if(count!=pos){
        printf("Invalid position.\n");
        return first;
    }
    prev->link = cur->link;
    printf("%d deleted!\n", cur->info);
    freenode(cur);
    return first;
}

NODE reverse(NODE first){
    NODE cur, temp;
    cur = NULL;
    while(first!=NULL){
        temp = first;
        first = first->link;
        temp->link = cur;
        cur = temp;
    }
    return cur;
}

NODE insert_pos(int item, int pos, NODE first){
    NODE temp;
    NODE prev, cur;
    int count;

    temp=getnode();
    temp->info = item;
    temp->link = NULL;

    if(first==NULL && pos==1){
        return temp;
    }
    if(first == NULL){
        printf("Invalid position!\n");
        return first;
    }
    if(pos==1){
        temp->link = first;
        return temp;
    }
    count = 1;
    prev = NULL;
    cur = first;
    while(cur!=NULL && count!=pos){
        prev = cur;
        cur = cur->link;
        count++;
    }
    if(count == pos){
        prev->link = temp;
        temp->link = cur;
        return first;
    }
    printf("Invalid position.\n");
    return first;
}

void main(){
    NODE first = NULL;
    int choice, item, key, pos;

    for(;;){
        printf("1.INSERT FRONT  2.DELETE FRONT  3.INSERT REAR   4.DELETE REAR  5.DISPLAY    6.SEARCH    7.DELETE(BY INFO)   8.DELETE(BY POS)    9.INSERT(BY POS)    10.REVERSE   11.QUIT\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);

        switch(choice){
            case 1 :
                printf("Enter the item to be inserted : \n");
                scanf("%d", &item);
                first = insert_front(item, first);
                break;
            case 2 :
                first = delete_front(first);
                break;
            case 3 : 
                printf("Enter the item to be inserted : \n");
                scanf("%d", &item);
                first = insert_rear(item, first);
                break;
            case 4 : 
                first = delete_rear(first);
                break;
            case 5 :
                display(first);
                break;
            case 6 :
                printf("Enter the item to be searched : \n");
                scanf("%d", &key);
                search(key, first);
                break;
            case 7 :
                printf("Enter the element to be deleted : \n");
                scanf("%d", &key);
                first = delete_info(key, first);
                break;
            case 8 :
                printf("Enter the position to be deleted : \n");
                scanf("%d", &pos);
                first = delete_pos(pos, first);
                break;
            case 9 :
                printf("Enter the position to be inserted : \n");
                scanf("%d", &pos);
                printf("Enter the item to be added : \n");
                scanf("%d", &item);
                first = insert_pos(item, pos, first);
                break;
            case 10 :
                printf("Reversed the list!\n");
                first = reverse(first);
                break;
            case 11 :
                printf("Exiting!");
                exit(0);
            default : 
                printf("Invalid choice!\n");
                break;
        }
    }
}