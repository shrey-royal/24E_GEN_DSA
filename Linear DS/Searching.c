#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int linearSearch(int *arr, int size, int target) {
    // O(n) -> time complexity
    // O(1) -> space complexity

    for (int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int *arr, int low, int high, int target) {
    // O(log n) -> time complexity
    // O(1) -> space complexity (if recursive without optimization O(log n))

    // Recursive Approach
    if(high > low) {
        int mid = (low + high) / 2;

        if(arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            return binarySearch(arr, low, mid-1, target);
        } else {
            return binarySearch(arr, mid+1, high, target);
        }
    }
    return -1;

    // Iterative Approach
    // int count = 0;
    // int mid = (low + high)/2;

    // while(arr[mid] != target) {
    //     count++;
    //     if (low >= high || high < 0) {
    //         printf("\nCount = %d\n", count);
    //         return -1;
    //     }

    //     //left sub-array
    //     if (arr[mid] > target) high = mid-1;

    //     //right sub-array
    //     if (arr[mid] < target) low = mid+1;

    //     mid = (low + high) / 2;
    // }
    // printf("\nCount = %d\n", count);
    // return mid;
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
        arr[i] = rand() % 10000;
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
        arr[i] = i+1;
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

int main() {
    srand(time(0));
    // testLinearSearch();
    testBinarySearch();

    return 0;
}