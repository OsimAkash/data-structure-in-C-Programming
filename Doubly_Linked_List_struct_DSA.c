#include <stdio.h>
#include <stdlib.h>

// Define the Node structure with previous and next pointers
struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;
struct Node *tail = NULL;

// Function to create the first node in the list
void firstNode(int v) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->value = v;
    n->next = NULL;
    n->prev = NULL;
    head = n;
    tail = n;
}

// Function to add a node at the end of the list
void addNode(int v) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->value = v;
    n->next = NULL;
    n->prev = tail;
    tail->next = n;
    tail = n;
}

// Function to print the list from head to tail
void printList() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d->", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at a specific index
void insertNode(int idx, int v) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->value = v;
    n->next = NULL;
    n->prev = NULL;
    if (idx == 0) {
        n->next = head;
        if (head != NULL) {
            head->prev = n;
        }
        head = n;
        if (tail == NULL) { // If the list was empty, update the tail
            tail = n;
        }
    } else {
        int i = 0;
        struct Node *temp = head;
        while (temp != NULL) {
            if (i == idx - 1) {
                n->next = temp->next;
                n->prev = temp;
                if (temp->next != NULL) {
                    temp->next->prev = n;
                }
                temp->next = n;
                if (n->next == NULL) { // If new node is the last node, update the tail
                    tail = n;
                }
                break;
            }
            temp = temp->next;
            i++;
        }
    }
}

// Function to delete a node at a specific index
void deleteNode(int idx) {
    if (head == NULL) return; // List is empty

    if (idx == 0) {
        struct Node *toDelete = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else { // If the list becomes empty, update the tail
            tail = NULL;
        }
        free(toDelete);
    } else {
        int i = 0;
        struct Node *temp = head;
        while (temp != NULL) {
            if (i == idx - 1) {
                struct Node *toDelete = temp->next;
                if (toDelete != NULL) {
                    temp->next = toDelete->next;
                    if (toDelete->next != NULL) {
                        toDelete->next->prev = temp;
                    } else { // If deleted node was the last node, update the tail
                        tail = temp;
                    }
                    free(toDelete);
                }
                break;
            }
            temp = temp->next;
            i++;
        }
    }
}

int main() {
    firstNode(10);
    addNode(20);
    addNode(30);
    addNode(40);
    printList();
    insertNode(2, 600);
    printList();
    deleteNode(3);
    printList();

    return 0;
}