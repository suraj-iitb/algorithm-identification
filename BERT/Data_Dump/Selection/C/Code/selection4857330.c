#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

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

void selectionSort(int *arr, int len) {
    int i, j, min_index;
    int count = 0;
    for (i = 0; i < len-1; i++) {
        min_index = i;
        for (j = i; j < len; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (i != min_index) {
            swap(&arr[i], &arr[min_index]);
            count++;
        }
    }
    printArray(arr, len);
    printf("%d\n", count);
}

int main() {

    int n, i;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    return 0;
}

