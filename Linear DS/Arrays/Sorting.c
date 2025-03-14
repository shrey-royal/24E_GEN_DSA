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

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size-1; i++) {
        int min_index = i;
        for (int j = i+1; j < size; j++) {
            if(arr[min_index] > arr[j]) {
                min_index = j;
            }
        }
        if(min_index != i) {
            swap(arr+i, arr+min_index);
        }
    }
}

void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int j = i-1;
        int key = arr[i];
        // move all elements greater than key to one position
        while (j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        // find a correct position for key 
        arr[j+1] = key;
    }
}

/*
Partition method which selects a pivot
and places each element  which is less than pivot value to its left
and the elements greater than the pivot value to its right
*/
int partition(int arr[], int lower, int upper) {
    int i = (lower - 1);

    int pivot = arr[upper]; // select last element as pivot

    int j;
    for(j = lower; j < upper; j++) {
        if (arr[j] <= pivot) {
            // if current element is smaller than pivot
            i++;    // increase the index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[upper]);   // places the last element i.e., the pivot to its correct position
    
    return (i+1);
}

/*
This is where the sorting of the array takes place
*/
void quickSort(int arr[], int lower, int upper) {
    if (upper > lower) {
        // partitioning index is returned by the partition function
        // element is at its correct position
        int partitionIndex = partition(arr, lower, upper);

        // sorting elements before and after the partition index
        quickSort(arr, lower, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, upper);
    }
}

/*
    @brief Perform merge of segments.
    @param a array to sort
    @param l left index for merge
    @param m mid index of the array
    @param r right index for merge
 */
void merge(int *a, int l, int m, int r) {
    int left_size = m - l + 1, right_size = r - m;
    int left[left_size], right[right_size];

    for(int i=0; i<left_size; i++) left[i] = a[l + i];
    for(int i=0; i<right_size; i++) right[i] = a[m + 1 + i];

    int i=0, j=0, k=l;
    while (i < left_size && j < right_size)
        a[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];

    while (i < left_size) a[k++] = left[i++];
    while (j < right_size) a[k++] = right[j++];
}


/*  Merge sort algorithm implementation
    @param a array to sort
    @param l index to sort from
    @param r index to sort till
*/
void merge_sort(int *a, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
        merge(a, l, m, r);
    }
}


void test() {
    const int size = 1000000;
    // const int size = rand() % 500;  //0 to 499
    int *arr = (int *) calloc(size, sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 100) - 50;   //-50 to 49
    }

    // printf("\nBefore sorting: ");
    // display(arr, size);

    printf("\nSorting started!");
    clock_t start = clock();
    
    // bubbleSort(arr, size);
    // selectionSort(arr, size);
    // insertionSort(arr, size);
    // quickSort(arr, 0, size-1);
    merge_sort(arr, 0, size-1);
    
    clock_t end = clock();
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // printf("\nAfter sorting: ");
    // display(arr, size);

    printf("\nAlgorithm took %.4f seconds to sort %d elements.\n", time_taken, size);

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


/*
1. Bubble Sort - 🍋‍🟩
2. Selection Sort - 🍊
3. Insertion Sort - 🍇
4. Quick Sort - 🍉
5. Merge Sort - 🍍
*/