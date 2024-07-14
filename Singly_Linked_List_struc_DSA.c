#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value ;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void  firstNode (int v) {
    struct Node *n =(struct Node*)malloc(sizeof(struct Node));
    n->value =v;
    n->next= NULL;
    head = n;
    tail = n;
}
void addNode (int v) {
    struct Node * = (struct Node*)malloc(sizeof(struct Node));
    tail->next = n;
    n->value = v;
    n->next = NULL;
    tail = n;

}

void printList() {
    struct Node *temp = head;
    int i = 0;
    while(temp != NULL) {
        printf("%d->", temp->value);
        temp = temp->next;
        i++;
    }
    printf("\n");
}
void insertNode (int idx, int v) {
    struct Node *n = (struct  Node*) malloc (sizeof(struct Node));
    n->value = v;
    n->next  = NULL;
    if (idx == 0) {
        n->next = head;
        head = n;
    }  else {
        int i = 0;
        struct Node *temp = head;
        while(temp != NULL) {
            if (i == idx-1) {
                struct Node *newNext = temp->next;
                temp->next=n;
                n->next = newNext;
                

            }
            temp = temp->next;
            i++;

        }
    }

}

void deleteNode (int idx) {
    if (idx == 0) {
        head = head->next;
    } else {
        int i = 0;
        struct Node *temp = head;
        while (temp != NULL) {
            if(i == idx-1) {
                temp->next = temp->next->next;

            }
            temp = temp->next;
            i++;
        }
    }

}

int main () {
    firstNode(10);
    addNode(20);
    addNode(30);
    addNode(40);
    printList ();
    insertNode(2,600);
    printList(3);
    printList();
}