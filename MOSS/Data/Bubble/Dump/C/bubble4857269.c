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

void bubbleSort(int *arr, int len) {
    int i, j;
    int count = 0;
    for (i = 0; i < len; i++) {
        for (j = len-1; j > i; j--) {
            if (arr[j] < arr[j-1]) {
                swap(&arr[j], &arr[j-1]);
                count++;
            }
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

    bubbleSort(arr, n);

    return 0;
}

