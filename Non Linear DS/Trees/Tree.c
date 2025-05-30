#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
typedef struct Node* node;

struct Node {
    int data;
    node left;
    node right;
};

node createNode(int data) {
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node insert(node root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(node root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

node search(node root, int value) {
    if (root == NULL || root->data == value) return root;
    if (value < root->data) return search(root->left, value);
    return search(root->right, value);
}

int height(node root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void levelorderTraversal(node root) {
    if (root == NULL) return;

    node queue[10];
    int f=0, r=0;

    queue[r++] = root;

    printf("\nLevel Order Traversal: ");
    while (f<r) {
        node current = queue[f++];
        printf("%d ", current->data);
        if (current->left != NULL) queue[r++] = current->left;
        if (current->right != NULL) queue[r++] = current->right;

    }
}

node deleteNode(node root, int data) {
    if (root == NULL) return root;

    if (data < root->data) root->left = deleteNode(root->left, data);
    else if (data > root->data) root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            node temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node temp = root->left;
            free(root);
            return temp;
        }
    
        node temp = root->right;
        while(temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void findMinMax(node root, int* min, int* max) {
    if (root == NULL) return;

    if (root->data < *min) *min = root->data;
    if (root->data > *max) *max = root->data;
    

    findMinMax(root->left, min, max);
    findMinMax(root->right, min, max);
}

void printTree(node root, int space) {
    if (root == NULL) {
        return;
    }
    space += 4;
    printTree(root->right, space);
    for (int i = 4; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

// tree: 1 8 1 3 1 10 1 1 1 6 1 14 1 4 1 7 1 13
int main() {
    struct ListNode* head = NULL;
    node root = NULL;
    FILE *fp = NULL;
    int choice, data, min, max;

    do{
        system("cls");
        printTree(root, 0);
        printf("\n\nBinary Tree Operations Menu\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Height\n");
        printf("7. Level Order Traversal\n");
        printf("8. Delete\n");
        printf("9. Find Min and Max\n");
        printf("10. Display Tree\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            
            case 2:
                printf("\nInorder Traversal : ");
                inorder(root);
                printf("\n");
                system("pause");
                break;

            case 3:
                printf("\nPreorder Traversal : ");
                preorder(root);
                printf("\n");
                system("pause");
                break;

            case 4:
                printf("\nPostorder Traversal : ");
                postorder(root);
                printf("\n");
                system("pause");
                break;

            case 5:
                printf("\nPlease enter a value to search: ");
                scanf("%d", &data);

                if(search(root, data) != NULL) {
                    printf("\nKey %d found in the tree.\n", data);
                } else {
                    printf("\nKey %d not found in the tree.\n", data);
                }
                system("pause");
                break;

            case 6:
                printf("\nHeight of the tree: %d\n", height(root));
                system("pause");
                break;

            case 7:
                printf("\nLevelorder Traversal : ");
                levelorderTraversal(root);
                printf("\n");
                system("pause");
                break;

            case 8:
                printf("\nEnter the value to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;

            case 9:
                min = INT_MAX;
                max = INT_MIN;
                findMinMax(root, &min, &max);
                printf("\nMinimum value in the tree: %d", min);
                printf("\nMaximum value in the tree: %d\n", max);
                system("pause");
                break;

            case 10:
                printTree(root, 0);
                system("pause");
                break;

            case 0:
                printf("Exiting the program...\n");
                system("pause");
                break;
        }//end of switch
    } while(choice != 0);
}