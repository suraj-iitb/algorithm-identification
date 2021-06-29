#include <stdio.h>

void trace(int *a, int n)
{
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

void insertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int p = i - 1;
        while (p >= 0 && a[p] > key) {
            a[p+1] = a[p];
            p--;
        }
        a[p+1] = key;
        trace(a, n);
    }
}

int main()
{
    int n, a[110];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    trace(a, n);
    insertionSort(a, n);

    return 0;
}
