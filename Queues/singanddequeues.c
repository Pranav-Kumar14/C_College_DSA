#include<stdio.h>
#include<stdlib.h>
#include "queueops.h"

void main(){
    Queue q;
    q.f = 0; q.r = -1;
    int n, add, del;
 
    for(;;){
        int choice;
        printf("1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\nEnter : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter number of elements to be added : ");
                scanf("%d", &n);

                for(int i=0; i<n; i++){
                    printf("Enter element : ");
                    scanf("%d", &add);
                    insert_front(&q, add);
                }
                break;

            case 2:
                printf("Enter number of elements to be added : ");
                scanf("%d", &n);

                for(int i=0; i<n; i++){
                    printf("Enter element : ");
                    scanf("%d", &add);
                    insert_rear(&q, add);
                }
                break;

            case 3:
                printf("Enter number of elements to be deleted : ");
                scanf("%d", &del);

                for(int i=0; i<del; i++){
                    delete_front(&q);
                }
                break;
            
            case 4:
                printf("Enter number of elements to be deleted : ");
                scanf("%d", &del);

                for(int i=0; i<del; i++){
                    delete_rear(&q);
                }
                break;
            
            case 5:
                display(&q);
                break;

            default:
                exit(0);
        }
    
    }
    
}