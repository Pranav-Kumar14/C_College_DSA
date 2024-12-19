#include<stdio.h>
#include<stdlib.h>

float aver(int **table, int i, int n){
    float total = 0;
    for(int j=1; j<=n; j++){
        total+= table[i][j];
    }
    float avg = total/n;
    return avg;
}

void swaponavg(int **table, int m, int n){
    for(int i=0; i<m-1; i++){
        for(int j=i+1; j<m; j++){
            if(aver(table, i, n) < aver(table, j, n)){
                int *temp = table[i];
                table[i] = table[j];
                table[j] = temp;
            }
        }
    }
}

int main(){
    int m, n;
    int **table;

    printf("Enter the number of students : \n");
    scanf("%d", &m);
    printf("Enter the number of subjects : \n");
    scanf("%d", &n);

    table = (int**)calloc(m+1, sizeof(int*));
    for(int i=0; i<m; i++){
        table[i] = (int*)calloc(n+1, sizeof(int));
        printf("Enter the Student %d marks-> \n", i+1);
        for(int j=1; j<=n; j++){
            printf("Subject %d : ", j);
            scanf("%d", &table[i][j]);
        }
        table[i][0] = i+1;
    }

    printf("DISPLAYING THE STUDENTS\n");
    for(int i=0; i<m; i++){
        printf("Student %d marks ->\n", i+1);
        for(int j=1; j<=n; j++){
            printf("Subject %d : %d\t", j, table[i][j]);
        }
        printf("Avg : %f", aver(table, i, n));
        printf("\n");
    }
    
    swaponavg(table, m, n);

    printf("AVERAGES (in descending order)\n");
    for(int i=0; i<m; i++){
        printf("Student %d\t", table[i][0]);
        printf("Avg : %f\n", aver(table, i, n));
    }
    
    for(int i=0; i<m; i++)
        free(table[i]);
    free(table);
    return 0;
}