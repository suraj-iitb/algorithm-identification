#include <stdio.h>
#define N 100

void swapper(int *a, int *b) {
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void printlist(int A[N], int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d\n", A[i]);
        } else {
            printf("%d ", A[i]);
        }
    }
}

int main(void) {
    int i, j;
    int n, A[N], count = 0, minj;

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &A[i]);

    for (i = 0; i < n; i++) {
        minj = i;
        for (j = i; j < n; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        swapper(&A[i], &A[minj]);
        if (i != minj) count++;
    }
    printlist(A, n);
    printf("%d\n", count);

    return 0;
}
