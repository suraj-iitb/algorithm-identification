#include <cstdio>

void trace(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int value = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > value) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = value;
        trace(a, n);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    trace(a, n);
    insertionSort(a, n);
    return 0;
}
