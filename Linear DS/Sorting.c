#include<assert.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void display(const int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size-1; i++) {  
        bool swapped = false;
        for (int j = 0; j < size-1-i; j++) {    
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) {
            break;
        }
    }
}

void test() {
    const int size = 10000;
    // const int size = rand() % 500;  //0 to 499
    int *arr = (int *) calloc(size, sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 100) - 50;   //-50 to 49
    }

    // printf("\nBefore sorting: ");
    // display(arr, size);

    printf("\nSorting started!");
    clock_t start = clock();
    
    bubbleSort(arr, size);
    // selectionSort(arr, size);
    // insertionSort(arr, size);
    // quickSort(arr, 0, size-1);
    // merge_sort(arr, size, 0, size-1);
    
    clock_t end = clock();
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // printf("\nAfter sorting: ");
    // display(arr, size);

    printf("\nBubble sort took %.4f seconds to sort %d elements.\n", time_taken, size);

    for (int i = 0; i < size-1; i++) {
        assert(arr[i] <= arr[i+1]);
    }
    free(arr);
}

int main() {
    srand(time(NULL));
    
    test();

    return 0;
}