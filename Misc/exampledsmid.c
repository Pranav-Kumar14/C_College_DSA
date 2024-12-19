#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct StringArray{
    char **a;
    int size;
}StringArray;

void FindLongestWord(StringArray *strArray, int index, char *longestWord){
    int counter=0;
    static int longest=0;
    if(index == strArray->size){
        return;
    }
    int j=0;
    while(strArray->a[index][j]!='\0'){
        counter++;
        j++;
    }
    if(counter>longest){
        longest = counter;
        strcpy(longestWord, strArray->a[index]);
    }
    FindLongestWord(strArray, index+1, longestWord);
}

void displayLongestWord(char *longestWord){
    printf("The longest word is : %s\n", longestWord);
}

void main(){
    StringArray s;
    int n, i, j;
    printf("Enter the number of words : ");
    scanf("%d", &s.size);
    s.a = (char**)malloc(n * sizeof(char*));
    for(i=0; i<s.size; i++){
        s.a[i] = (char*)malloc(50 * sizeof(char));
        printf("Enter the word %d : ", i+1);
        scanf("%s", s.a[i]);
    }
    for(i=0; i<s.size; i++){
        printf("Word %d is : %s\n", i+1, s.a[i]);
    }
    char *longest;
    longest = (char*)malloc(50 * sizeof(char));
    longest = s.a[0];

    FindLongestWord(&s, 0, longest);
    displayLongestWord(longest);

    for(i=0; i<s.size; i++){
        free(s.a[i]);
    }
    free(s.a);
    free(longest);
}