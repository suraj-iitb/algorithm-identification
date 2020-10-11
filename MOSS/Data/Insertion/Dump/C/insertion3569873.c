#include <stdio.h>

void printArray(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d", a[i]);
        if (i != n - 1) printf(" ");
    }
    printf("\n");
}

void insertionSort(int *a, int n) {
    for (int i = 1; i < n; ++i) {
        printArray(a, n);
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = v;
    }
}

int main(void){
    int n;
    int a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    
    insertionSort(a, n);
    
    printArray(a, n);
}

