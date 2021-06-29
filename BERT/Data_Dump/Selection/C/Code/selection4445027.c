#include<stdio.h>

int selectionSort(int*, int);
void swap(int*, int*);
void printStr(int*, int);

int main(void) {
    int n, a[100];
    int swapTime;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    swapTime = selectionSort(a, n);

    printStr(a, n);
    printf("%d\n", swapTime);

    return 0;
}

int selectionSort(int *a, int n) {
    int swapTime = 0;
    for(int i = 0; i < n-1; i++) {
        int minj = i;
        for(int j = i; j < n; j++) {
            if(a[j] < a[minj]) {
                minj = j;
            }
        }
        if(a[i] != a[minj]) {
            swap(&a[i], &a[minj]);
            swapTime++;
        }
    }
    return swapTime;
}

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void printStr(int *a, int n) {
    int i;
    for(i = 0; i < n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[i]);
}

