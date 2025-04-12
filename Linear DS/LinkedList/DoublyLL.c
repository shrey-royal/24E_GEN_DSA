#include <stdio.h>
#include <stdlib.h>

typedef struct Node* node;

struct Node {
    int data;
    node prev;
    node next;
};

node createNode(int data) {
    node newNode = (node)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("\nMemory allocation failed!");
        exit(1);
    }
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

node insertAtFront(node head, int data) {
    node newNode = createNode(data);
    
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }

    return newNode;
}

node insertAtEnd(node head, int data) {
    node newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    node curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->prev = curr;

    return head;
}

node insertAtPosition(node head, int data, int position) {
    if (position == 1 || head == NULL) {
        return insertAtFront(head, data);
    }

    node newNode = createNode(data);
    node curr = head;
    int currentPosition = 1;

    while (curr != NULL && currentPosition < position - 1) {
        curr = curr->next;
        currentPosition++;
    }

    newNode->next = curr->next;
    newNode->prev = curr;
    if (curr->next != NULL) {
        curr->next->prev = newNode;
    }
    curr->next = newNode;

    return head;
}

node deleteAtFront(node head) {
    if (head == NULL) {
        printf("\nList is already empty. Nothing to delete.\n");
        return NULL;
    }

    node temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

node deleteAtEnd(node head) {
    //TODO
}

void printForward(node head) {
    printf("\nList > \tNULL <-> ");
    while(head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n\n");
}

void printAddr(node head) {
    printf("\nList:\n");
    while(head != NULL) {
        printf("[%p,  %d(%p),  %p]\n", head->prev, head->data, &head->data, head->next);
        head = head->next;
    }
    printf("\n\n");
}

int main() {
    node list = NULL;

    // list = insertAtFront(list, 11);
    // list = insertAtFront(list, 12);
    // list = insertAtFront(list, 13);
    // list = insertAtFront(list, 14);
    // list = insertAtFront(list, 15);
    // list = insertAtFront(list, 16);
    // list = insertAtFront(list, 17);
    // list = insertAtFront(list, 18);
    // list = insertAtFront(list, 19);
    // list = insertAtFront(list, 20);

    list = insertAtEnd(list, 11);
    list = insertAtEnd(list, 12);
    list = insertAtEnd(list, 13);
    list = insertAtEnd(list, 14);
    list = insertAtEnd(list, 15);
    list = insertAtEnd(list, 16);
    list = insertAtEnd(list, 17);
    list = insertAtEnd(list, 18);
    list = insertAtEnd(list, 19);
    list = insertAtEnd(list, 20);

    
    list = insertAtPosition(list, 121, 11);
    // list = insertAtPosition(list, 12);

    printForward(list);

    list = deleteAtFront(list);
    
    printForward(list);
    // printAddr(list);
}