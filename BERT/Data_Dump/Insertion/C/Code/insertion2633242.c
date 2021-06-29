#include <stdio.h>
#include <stdlib.h>

void insertionSort(int*, int);
void printArray(int*, int);

int main(void) {
    int n, *a, i = 0;
    scanf("%d", &n);
    a = malloc(sizeof(int) * n);
    while (i < n) {
        scanf("%d", &a[i]);
        i++;
    }
    printArray(a, n);
    insertionSort(a, n);
    return 0;
}

void insertionSort(int *a, int n) {
    int i, j, v;
    for (i = 1; i < n; i++) {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        printArray(a, n);
    }
}

void printArray(int *a, int n) {
    int i = 0;
    while (i < n - 1) {
        printf("%d ", a[i]);
        i++;
    }
    printf("%d\n", a[i]);
}
