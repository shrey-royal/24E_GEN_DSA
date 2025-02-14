#include<stdio.h>
#include<stdlib.h>

void printArray(char* arr, int size) {
    printf("-> arr[%d] = {", size);
    for (int i = 0; i < size; i++) {
        printf("%c, ", arr[i]);
    }
    printf("\b\b}\n");
}

void revArray(char* arr, int size) {
    int start = 0, end = size-1;
    while(start < end) {
        if(start%2 == 0) {
            char temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
        start++;
        end--;
    }
}

int main() {
    int size=0;
    char* arr = (char*)malloc(20);
    
    sscanf("gautam Ghambhir", "%[^\n]", arr);
    while(*(arr+size) != '\0') size++;

    printArray(arr, size);
    revArray(arr, size);
    printArray(arr, size);

    return 0;
}