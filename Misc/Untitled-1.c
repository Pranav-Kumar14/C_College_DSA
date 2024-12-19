#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    //number guessing game
    const int MIN = 1;
    const int MAX = 100;
    int guess;
    int guesses;
    int answer;

    srand(time(0));

    answer= (rand()%MAX) + MIN;

    
    do{
        printf("Enter a guess : ");
        scanf("%d",&guess);
        if(guess>answer)
        {
            printf("Too high!\n");
            continue;
        }
        else if(guess<answer)
        {
            printf("Too low!\n");
            continue;
        }
        else
        {
            printf("Correct!\n");
            break;
        }
        guesses++;
    }while(guess!=answer);

    printf("Answer is %d\n",answer);
    printf("Guesses taken : %d\n",guesses);

    return 0;
}
