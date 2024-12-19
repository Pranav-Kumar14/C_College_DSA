#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void main(){
    int a = 5;
    int b = 6;
    printf("Values before swapping : a->%d b->%d\n", a, b);
    swap(&a, &b);
    printf("Values after swapping : a->%d b->%d\n", a, b);
}