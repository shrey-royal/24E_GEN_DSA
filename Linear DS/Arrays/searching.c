#include<stdio.h>
#include<stdlib.h>

int linearSearch(int *arr, int size, int target) {
    //O(n) -> time Complexity
    //O(1) -> space Complexity

    for (int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void printArray(int *arr, int size) {
    printf("\nArray elements: { ");
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b }");
}

void testLinearSearch() {
    int size;

    printf("\nEnter size of the array: ");
    scanf("%d", &size);

    int arr[size], target;
    
    for (size_t i = 0; i < size; i++) {
        arr[i] = rand();
    }
    
    printArray(arr, size);

    printf("\nEnter target: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target);

    if(result != -1) {
        printf("\n%d found at %d index", target, result);
    } else {
        printf("\n%d not found", target);
    }
}

void main() {
    testLinearSearch();
}