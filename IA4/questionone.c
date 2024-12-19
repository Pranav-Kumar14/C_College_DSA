#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char tag[10]; 
    char expression[100];  
    int result;  
    struct Node* next; 
    struct Node* prev; 
} Node;

Node* Insert(Node* head, char* tag, char* expression) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->tag, tag);
    strcpy(newNode->expression, expression);
    newNode->result = 0; 
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode; 
}

void Display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("Tag: %s, Expression: %s, Result: %d\n", temp->tag, temp->expression, temp->result);
        temp = temp->next;
    }
}

int CheckExpression(char* expr) {
    int count = 0;
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') count++;
        else if (expr[i] == ')') count--;
        if (count < 0) return 0; 
    }
    return (count == 0);  
}

int ComputePostfix(char* expr) {
    int stack[100], top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            stack[++top] = expr[i] - '0';  
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            int b = stack[top--];
            int a = stack[top--];
            switch (expr[i]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }
    return stack[top];  
}

void ProcessList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        if (CheckExpression(temp->expression)) {
            temp->result = ComputePostfix(temp->expression);
        } else {
            printf("Invalid expression: %s\n", temp->expression);
        }
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    int choice;
    char tag[10], expression[100];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Expression\n");
        printf("2. Display Expressions\n");
        printf("3. Process Expressions\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter tag (e.g., <TEST>, <POSTFIX>): ");
                scanf("%s", tag);
                printf("Enter expression: ");
                scanf("%s", expression);
                head = Insert(head, tag, expression);
                break;
            case 2:
                Display(head);
                break;
            case 3:
                ProcessList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
