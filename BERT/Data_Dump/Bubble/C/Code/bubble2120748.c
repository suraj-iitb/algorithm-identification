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
    int i;
    int n, flag = 1, A[N], count = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &A[i]);

    while (flag) {
        flag = 0;
        for (i = n - 1; i >= 1; i--) {
            if (A[i] < A[i - 1]) {
                swapper(&A[i], &A[i - 1]);
                flag = 1;
                count++;
            }
        }
    }
    printlist(A, n);
    printf("%d\n", count);

    return 0;
}
