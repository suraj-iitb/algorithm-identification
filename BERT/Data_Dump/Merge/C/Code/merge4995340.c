#include <stdio.h>
#include <stdlib.h>

int count = 0;

void display(int A[], int size) {
    for (int i = 0; i < size - 1; i = i + 1) {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[size - 1]);
}

void merge(int A[], int p, int q, int r) {  // p <= q < r
    int n1 = q - p + 1;    // n1 は A[p, ..., q]　の要素数 q - (p - 1)
    int n2 = r - q;        // n2 は A[q+1, ..., r] の要素数 r - q
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i = i + 1) {
        L[i] = A[p + i];
    }
    for (int i = 0; i < n2; i = i + 1) {
        R[i] = A[q + i + 1];
    }

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k = k + 1) {
        if ((L[i] <= R[j] && i < n1) || (j == n2 && i < n1)) {
            A[k] = L[i];
            i = i + 1;
            count++;
        } else if ((R[j] < L[i] && j < n2) || (i == n1 && j < n2)) {
            A[k] = R[j];
            j = j + 1;
            count++;
        }

    }
}

void merge_sort(int A[], int p, int r) {
    if (p < r) {
        int q;
        q = (p + r)/2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int* a;
    a = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    merge_sort(a, 0, n - 1);
    display(a, n);
    printf("%d\n", count);
    return 0;
}

