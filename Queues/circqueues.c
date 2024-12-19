#include<stdio.h>
#include<stdlib.h>
#include "circqueueop.h"

void main(){
    Cqueue q;
    q.f = 0; q.r = -1; q.count = 0;
    int n, add, del;
 
    for(;;){
        int choice;
        printf("1.Insert Rear\n2.Delete Front\n3.Display\nEnter : ");
        scanf("%d", &choice);
        switch(choice){

            case 1:
                printf("Enter number of elements to be added : ");
                scanf("%d", &n);

                for(int i=0; i<n; i++){
                    printf("Enter element : ");
                    scanf("%d", &add);
                    insert_rearc(&q, add);
                }
                break;

            case 2:
                printf("Enter number of elements to be deleted : ");
                scanf("%d", &del);

                for(int i=0; i<del; i++){
                    delete_frontc(&q);
                }
                break;

            case 3:
                displayc(&q);
                break;

            default:
                exit(0);
        }
    }    
}