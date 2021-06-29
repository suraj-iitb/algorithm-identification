#include <stdio.h>

int insertionSort(int *a, int *n) {
    int i, v, j, k;

    for (i = 0; i < *n; i++) {
        v = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;

        for (k = 0; k < *n; k++) {
            printf("%d", a[k]);
            if (k < *n - 1) printf(" ");
            else printf("\n");
        }
    }

    return 0;
}

int main(void) {
    int n, f;
    scanf("%d", &n);
    int A[n];

    for (f = 0; f < n; f++) {
        scanf("%d", &A[f]);
    }

    insertionSort(&A, &n);

    return 0;
}
