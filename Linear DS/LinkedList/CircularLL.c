#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;

struct Node {
    int data;
    node *next;
};

// Insert at front
node* insertAtFront(node* head, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = newNode;

    if (head == NULL) {
        return newNode;
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

// Insert at end
node* insertAtEnd(node* head, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = newNode;

    if (head == NULL) {
        return newNode;
    }

    node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Insert at position
node* insertAtPosition(node* head, int data, int position) {
    if (position <= 1 || head == NULL) {
        return insertAtFront(head, data);
    }

    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;

    node* temp = head;
    int count = 1;

    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Delete at first
node* deleteAtFirst(node* head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == head) {
        free(head);
        return NULL;
    }

    node* last = head;
    while(last->next != head) {
        last = last->next;
    }

    node* temp = head;
    head = head->next;
    last->next = head;
    free(temp);

    return head;
}

// Delete at end
node* deleteAtEnd(node* head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == head) {
        free(head);
        return NULL;
    }

    node* temp = head;
    node* prev = NULL;

    while(temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
    return head;
}

// Print
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

// Main
void main() {
    node* head = NULL;
    int data, position, choice;

    while(1) {
        system("cls");
        print(head);
        printf("\n1. Insert At Front");
        printf("\n2. Insert At End");
        printf("\n3. Insert At Position");
        printf("\n4. Delete At Front");
        printf("\n5. Delete At End");
        printf("\n6. Print");
        printf("\n0. Exit\n-> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtFront(head, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                head = insertAtPosition(head, data, position);
                break;

            case 4:
                head = deleteAtFirst(head);
                break;

            case 5:
                head = deleteAtEnd(head);
                break;

            case 6:
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
