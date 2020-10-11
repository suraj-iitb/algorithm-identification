#include <stdio.h>
#include <stdlib.h>

int selectionSort(int*, int);
void printArray(int*, int);

int main(void) {
    int n, *a, i = 0, count;
    scanf("%d", &n);
    a = malloc(sizeof(int) * n);
    while (i < n) {
        scanf("%d", &a[i]);
        i++;
    }
    count = selectionSort(a, n);
    printArray(a, n);
    printf("%d\n", count);
    return 0;
}

int selectionSort(int *a, int n) {
    int i, j, minj, w, count = 0;
    for (i = 0; i < n; i++) {
        minj = i;
        for (j = i; j < n; j++) {
            if (a[j] < a[minj])
                minj = j;
        }
        if (a[i] != a[minj]) {
            count++;
            w = a[i];
            a[i] = a[minj];
            a[minj] = w;
        }
    }
    return count;
}

void printArray(int *a, int n) {
    int i = 0;
    while (i < n - 1) {
        printf("%d ", a[i]);
        i++;
    }
    printf("%d\n", a[i]);
}

