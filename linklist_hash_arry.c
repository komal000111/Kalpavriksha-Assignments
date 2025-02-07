#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    int value;
    struct node *next;
} node;

node *hashTable[1000];
int hashTableSize = 10;

void presentation() {
    printf("\t\tHash Table C Program\n\n");
    printf("\t1. Add Node\n");
    printf("\t2. Search Node\n");
    printf("\t3. Delete Node\n");
    printf("\t4. Print Hash Table\n");
    printf("\t5. Exit\n");
}

void addNode() {
    node *n = (node *)malloc(sizeof(node));
    printf("Enter key: ");
    scanf("%d", &(n->key));
    printf("Enter value: ");
    scanf("%d", &(n->value));
    n->next = NULL;

    int hashIndex = n->key % hashTableSize;
    if (hashTable[hashIndex] == NULL) {
        hashTable[hashIndex] = n;
    } else {
        node *temp = hashTable[hashIndex];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }
}

node* searchNode(int key, int value) {
    int hashIndex = key % hashTableSize;
    node *n = hashTable[hashIndex];
    while (n != NULL) {
        if (n->key == key && n->value == value) {
            return n;
        }
        n = n->next;
    }
    return NULL;
}

void deleteNode(int key, int value) {
    int hashIndex = key % hashTableSize;
    node *n = hashTable[hashIndex], *prev = NULL;
    
    while (n != NULL && !(n->key == key && n->value == value)) {
        prev = n;
        n = n->next;
    }

    if (n == NULL) {
        printf("Node not found!\n");
    } else {
        if (prev == NULL) {
            hashTable[hashIndex] = n->next;
        } else {
            prev->next = n->next;
        }
        free(n);
        printf("Node deleted successfully.\n");
    }
}

void printList(node *n) {
    while (n != NULL) {
        printf(" (%d, %d) ->", n->key, n->value);
        n = n->next;
    }
    printf(" NULL");
}

void printHashTable() {
    for (int i = 0; i < hashTableSize; i++) {
        printf("\nHashTable[%d]:", i);
        printList(hashTable[i]);
    }
    printf("\n");
}

int main() {
    for (int i = 0; i < hashTableSize; i++) {
        hashTable[i] = NULL;
    }

    int action = 0;

    presentation();
    do {
        printf("\nChoose action (1-5): ");
        scanf("%d", &action);

        int key, value;
        switch (action) {
            case 1:
                addNode();
                break;
            case 2:
                printf("Enter key and value to search: ");
                scanf("%d %d", &key, &value);
                node *foundNode = searchNode(key, value);
                if (foundNode == NULL) {
                    printf("Node not found!\n");
                } else {
                    printf("Node found: (%d, %d)\n", foundNode->key, foundNode->value);
                }
                break;
            case 3:
                printf("Enter key and value to delete: ");
                scanf("%d %d", &key, &value);
                deleteNode(key, value);
                break;
            case 4:
                printHashTable();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid action. Try again.\n");
                break;
        }
    } while (action != 5);

    return 0;
}
