#define QUEUE_SIZE 10

typedef struct Cqueue{
    int q[QUEUE_SIZE];
    int f;
    int r;
    int count;
}Cqueue;

void insert_rearc(Cqueue *ps, int item){
    if(ps->count == QUEUE_SIZE){
        printf("Queue Overflow!\n");
        return;
    }
    ps->r = (ps->r + 1)%QUEUE_SIZE;
    ps->q[(ps->r)] = item;
    ps->count+=1;
}

void delete_frontc(Cqueue *ps){
    if(ps->count==0){
        printf("Queue underflow!\n");
        return;
    }
    printf("Item deleted : %d\n", ps->q[(ps->f)]);
    ps->f = (ps->f + 1)%QUEUE_SIZE;
    ps->count -= 1;
}

void displayc(Cqueue *ps){
    if(ps->count==0){
        printf("The queue is empty.\n");
        return;
    }
    printf("Queue is -> \n");
    for(int i = 0; i<= ps->count; i++){
        printf("%d\n", ps->q[ps->f]);
        ps->f = (ps->f +1)%QUEUE_SIZE;
    }
}