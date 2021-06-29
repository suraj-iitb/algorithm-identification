#include <stdio.h>
#define k 10001

int C[k] = {};

int CountingSort(int *A, int *B, int n) {
    int i, j;

    for (j = 1; j <= n; j++) C[A[j]]++;
    for (i = 1; i <= k; i++) C[i] += C[i - 1];
    
    for (j = n; j >= 1; j--) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main(void) {
    int n, i, j;
    scanf("%d", &n);
    int A[n+1]; int B[n+1];

    for (i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }

    CountingSort(A, B, n);

    for (i = 1; i <= n; i++) {
        printf("%d", B[i]);
        if (i < n) printf(" ");
        else printf("\n");
    }

    return 0;
}
