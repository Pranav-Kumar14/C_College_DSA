#define QUEUE_SIZE 10

typedef struct Queue{
    int q[QUEUE_SIZE];
    int f;
    int r;
}Queue;

void insert_rear(Queue *ps, int item){
    if(ps->r == QUEUE_SIZE-1){
        printf("Queue Overflow!\n");
        return;
    }
    ps->q[++(ps->r)] = item;
}

void delete_front(Queue *ps){
    if(ps->f > ps-> r){
        printf("Queue underflow!\n");
        return;
    }
    printf("Item deleted : %d\n", ps->q[(ps->f)++]);
    if(ps->f > ps->r){
        ps->f = 0;
        ps->r = -1;
    }
}

void display(Queue *ps){
    if(ps->f > ps->r){
        printf("The queue is empty.");
        return;
    }
    printf("Queue is -> \n");
    for(int i = ps->f; i<= ps->r; i++){
        printf("%d\n", ps->q[i]);
    }
}

void insert_front(Queue *ps, int item){
    if(ps->f==0 && ps->r==-1){
        ps->q[++(ps->r)] = item;
        return;
    }
    if(ps->f!=0){
        ps->q[(--(ps->f))] = item;
        return;
    }
    printf("Front insertion not possible");
}

void delete_rear(Queue *ps){
    if(ps->f > ps->r){
        printf("Queue Underflow!");
        return;
    }
    printf("Element deleted %d\n", ps->q[(ps->r)--]);
    if(ps->f > ps->r){
        ps->f = 0;
        ps->r = -1;
    }
}
