#define QUEUE_SIZE 5

typedef struct Pqueue{
    int q[QUEUE_SIZE];
    int f;
    int r;
}Pqueue;

void insert_rearp(Pqueue *ps, int item){
    int j;
    if(ps->r == QUEUE_SIZE-1){
        printf("Queue Overflow!\n");
        return;
    }
    j = ps->r;
    while(j>=0 && item<ps->q[j]){
        ps->q[j+1] = ps->q[j];
        j--;
    }
    ps->q[j+1] = item;
    ps->r = ps->r + 1;
}

void delete_frontp(Pqueue *ps){
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

void displayp(Pqueue *ps){
    if(ps->f > ps->r){
        printf("The queue is empty.");
        return;
    }
    printf("Queue is -> \n");
    for(int i = ps->f; i<= ps->r; i++){
        printf("%d\n", ps->q[i]);
    }
}