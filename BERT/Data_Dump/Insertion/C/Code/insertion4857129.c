#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i == len-1) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
}

void insertionSort(int *arr, int len) {
    int i, key, j;
    printArray(arr, len);
    for (i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;
        while (arr[j] > key && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        printArray(arr, len);
    }
}

int main() {
    
    int i, len;
    scanf("%d", &len);
    int arr[len];
    for (i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, len);

    return 0;
}

