#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

void swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int binarySearch(int *arr, int low, int high, int target) {
    // O(log n) -> time complexity
    // O(1) -> space complexity (if recursive without optimization O(log n))

    //Iterative approach
    int count = 0;
    int mid = (low + high) / 2;

    while(arr[mid] != target) {
        count++;
        if(low >= high || high < 0) {
            printf("\nCount = %d", count);
            return -1;
        }

        if (target < arr[mid]) {    //left sub-array
            high = mid - 1;
        }

        if(target > arr[mid]) { //right sub-array
            low = mid + 1;
        }

        mid = (low + high) / 2;
    }
    printf("\nCount: %d", count);
    return mid;
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

void testBinarySearch() {
    int size;

    printf("\nEnter size of the array: ");
    scanf("%d", &size);

    int arr[size], target;
    
    for (size_t i = 0; i < size; i++) {
        // arr[i] = i+1;
        arr[i] = rand();
    }

    for (int i = 0; i < size-1; i++) {
        bool swapped = false;
        for (int j = 0; j < size-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    
    printArray(arr, size);

    printf("\nEnter target: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, size-1, target);

    if(result != -1) {
        printf("\n%d found at %d index", target, result);
    } else {
        printf("\n%d not found", target);
    }
}

void main() {
    // testLinearSearch();
    testBinarySearch();
}