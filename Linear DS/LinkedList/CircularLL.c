#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;

struct Node {
    int data;
    node *next;
};

node* insertAtFront(node* head, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = newNode;

    if (head == NULL) {
        head = newNode;
        return head;
    }

    node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;

    return head;
}

node* insertAtEnd(node* head, int data) {
    // TODO
}

node* insertAtPosition(node* head, int data, int position) {
    // TODO
}

node* deleteAtFirst(node* head) {
    // TODO
}

node* deleteAtEnd(node* head) {
    // TODO
}

void print(node* head) {
    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    node* temp = head;
    printf("\nList: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("HEAD\n");
}

void main() {
    node* head = NULL;
    int data, choice;

    while(1) {
        system("cls");
        print(head);
        printf("\n1. Insert At Front");
        printf("\n2. Insert At End");
        printf("\n3. Insert At Position");
        printf("\n4. Print");
        printf("\n0. Exit\n-> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtFront(head, data);
                break;

            case 2:
                // TODO
                break;

            case 3:
                // TODO
                break;

            case 4:
                print(head);
                system("pause");
                break;

            case 0:
                exit(0);
            
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}