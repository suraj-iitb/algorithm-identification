#define N 105
#include <stdio.h>

void showArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
}

void InsertionSort(int a[], int n) {
    showArray(a, n);
    for (int i = 1; i < n; i++) {
        int val = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > val) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = val;
        showArray(a, n);
    }
}

int main() {
    int a[N];
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    InsertionSort(a, n);
    return 0;
}

