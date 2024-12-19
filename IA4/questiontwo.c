#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100

typedef enum { FILE_TYPE, DIRECTORY_TYPE } NodeType;

typedef struct Node {
    char name[MAX_NAME];  
    NodeType type;     
    int size;            
    struct Node* parent; 
    struct Node* children; 
    struct Node* next;  
} Node;

Node* createNode(const char* name, NodeType type, int size) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->type = type;
    newNode->size = (type == FILE_TYPE) ? size : 0;  
    newNode->parent = NULL;
    newNode->children = NULL;
    newNode->next = NULL;
    return newNode;
}

void addChild(Node* parent, Node* child) {
    child->parent = parent;
    child->next = parent->children;
    parent->children = child;
}

void deleteNode(Node* node) {
    if (node == NULL) return;

    Node* child = node->children;
    while (child != NULL) {
        Node* next = child->next;
        deleteNode(child);
        child = next;
    }

    free(node);
}

void listContents(Node* dir) {
    if (dir->type != DIRECTORY_TYPE) {
        printf("%s is not a directory.\n", dir->name);
        return;
    }

    Node* child = dir->children;
    while (child != NULL) {
        printf("%s (%s, Size: %d)\n", child->name,
               (child->type == FILE_TYPE) ? "File" : "Directory",
               child->size);
        child = child->next;
    }
}

void moveNode(Node* node, Node* newParent) {
    if (node->parent != NULL) {
        Node* prev = NULL;
        Node* child = node->parent->children;

        while (child != NULL && child != node) {
            prev = child;
            child = child->next;
        }

        if (prev == NULL) {  
            node->parent->children = node->next;
        } else {
            prev->next = node->next;
        }
    }

    addChild(newParent, node);
}

Node* findNode(Node* dir, const char* name) {
    if (strcmp(dir->name, name) == 0) {
        return dir;
    }

    Node* child = dir->children;
    while (child != NULL) {
        Node* found = findNode(child, name);
        if (found != NULL) {
            return found;
        }
        child = child->next;
    }
    return NULL; 
}

int calculateSize(Node* dir) {
    if (dir->type == FILE_TYPE) {
        return dir->size;
    }

    int totalSize = 0;
    Node* child = dir->children;
    while (child != NULL) {
        totalSize += calculateSize(child);
        child = child->next;
    }
    return totalSize;
}

int main() {
    Node* root = createNode("root", DIRECTORY_TYPE, 0);

    int choice;
    char name[MAX_NAME];
    int size;
    Node* node;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add File/Directory\n");
        printf("2. Delete File/Directory\n");
        printf("3. List Contents\n");
        printf("4. Move File/Directory\n");
        printf("5. Find File/Directory\n");
        printf("6. Calculate Directory Size\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter 1 for File, 2 for Directory: ");
                scanf("%d", &size);

                if (size == 1) {
                    printf("Enter file size: ");
                    scanf("%d", &size);
                    node = createNode(name, FILE_TYPE, size);
                } else {
                    node = createNode(name, DIRECTORY_TYPE, 0);
                }
                addChild(root, node);
                break;

            case 2:
                printf("Enter name to delete: ");
                scanf("%s", name);
                node = findNode(root, name);
                if (node != NULL) {
                    deleteNode(node);
                    printf("Deleted %s\n", name);
                } else {
                    printf("%s not found.\n", name);
                }
                break;

            case 3:
                listContents(root);
                break;

            case 4:
                printf("Enter name to move: ");
                scanf("%s", name);
                node = findNode(root, name);
                if (node != NULL) {
                    printf("Enter new parent name: ");
                    scanf("%s", name);
                    Node* newParent = findNode(root, name);
                    if (newParent != NULL && newParent->type == DIRECTORY_TYPE) {
                        moveNode(node, newParent);
                        printf("Moved %s to %s\n", node->name, newParent->name);
                    } else {
                        printf("Invalid parent directory.\n");
                    }
                } else {
                    printf("%s not found.\n", name);
                }
                break;

            case 5:
                printf("Enter name to find: ");
                scanf("%s", name);
                node = findNode(root, name);
                if (node != NULL) {
                    printf("Found %s\n", name);
                } else {
                    printf("%s not found.\n", name);
                }
                break;

            case 6:
                printf("Total size of root: %d\n", calculateSize(root));
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
