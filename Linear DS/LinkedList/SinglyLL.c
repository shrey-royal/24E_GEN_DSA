#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\nMemory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while(last->next != NULL) last = last->next;
    last->next = newNode;
}

void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid Position.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is out of bounds.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int searchByValue(struct Node* head, int key) {
    while (head != NULL) {
        if (head->data == key) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void reverseList(struct Node** head) {
    struct Node* current = *head, *prev = NULL, *next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("\nList is Empty!\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("\nList is Empty!\n");
        return;
    }

    struct Node* temp = *head;

    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    int length = getLength(*head);
    if (position < 1 || position > length) {
        printf("Invalid position!\n");
        return;
    }

    struct Node* temp = *head;
    if (position == 1) {
        *head = (*head)->next;
        free(temp);
        return;
    }

    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

void printList(struct Node* head) {
    printf("\nList: ==> ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void printFromEnd(struct Node* head) {
    if (head == NULL) return;
    printFromEnd(head->next);
    printf("%d <- ", head->data);
}


// Input: 2 22 2 23 2 24 2 25 2 26 2 27 1 21
int main() {
    int choice, data, position, key;
    struct Node* head = NULL;
    
    while(choice != 0) {
        system("cls");
        printList(head);

        printf("\n\n\n1. Insert at beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Search By Value");
        printf("\n5. Length of the list");
        printf("\n6. Reverse the List");
        printf("\n7. Delete at beginning");
        printf("\n8. Delete at end");
        printf("\n9. Delete at Position");
        printf("\n10. Print list from beginning");
        printf("\n11. Print list from end");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;

            case 2:
                printf("\nEnter the data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 3:
                printf("\nEnter the position: ");
                scanf("%d", &position);
                printf("\nEnter the data: ");
                scanf("%d", &data);
                insertAtPosition(&head, data, position);
                break;

            case 4:
                printf("\nEnter the key to search from the list: ");
                scanf("%d", &key);
                searchByValue(head, key) ? printf("\n%d present in the list...\n", key) : printf("\n%d is not present in the list...\n", key);
                system("pause");
                break;

            case 5:
                printf("\nLength of the list: %d\n", getLength(head));
                system("pause");
                break;
    
            case 6:
                reverseList(&head);
                break;

            case 7:
                deleteAtBeginning(&head);
                break;

            case 8:
                deleteAtEnd(&head);
                break;

            case 9:
                printf("\nEnter the position to delete the node: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 10:
                printList(head);
                break;

            case 11:
                printf("\nList from End: ");
                printFromEnd(head);
                printf("NULL\n");
                system("pause");
                break;

            case 0:
                printf("\nExiting...\n");
                break;
            
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }// end of switch
    }// end of while
    return 0;
}// end of main