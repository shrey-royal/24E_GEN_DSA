#include<stdio.h>

void scanArray(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%c", &arr[i]);
    }
}

void printArray(char arr[], int size) {
    printf("\n-> arr[%d] = {", size);
    for(int i=0; i<size; i++) {
        printf("%c, ", arr[i]);
    }
    printf("\b\b}\n");
}

void reverseArray(char arr[], int start, int end) {
    while(start < end) {
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(){
    // int arr[] = {1, 2, 3, 4, 5, 6};
    char arr[5];
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Enter the array elements: ");
    scanArray(arr, size);

    printf("Original array: ");
    printArray(arr, size);

    reverseArray(arr, 0, size-1);

    printf("Reversed array: ");
    printArray(arr, size);
}

//task: reverse int array
//task: reverse even ints only from the array