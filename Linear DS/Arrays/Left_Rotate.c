#include<stdio.h>

void printArray(int arr[], int size) {
    printf("\n-> arr[%d] = {", size);
    for(int i=0; i<size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b}\n");
}

void leftRotate(int arr[], int d, int size) {
    int temp[size];
    int k = 0;

    for (int i=d; i<size; i++) {
        temp[k] = arr[i];
        k++;
    }

    for(int i=0; i<d; i++) {
        temp[k] = arr[i];
        k++;
    }

    for(int i=0; i<size; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int d = 7;

    // leftRotate(arr, d, size);
    rightRotate(arr, d, size);
    printArray(arr, size);

    return 0;
}

//rightRotate(arr, d, size);