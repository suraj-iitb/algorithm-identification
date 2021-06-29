#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static void CountingSort(int A[], int B[], int n, int k) {
    int i, j;
    int* C = malloc(sizeof(int) * (k + 1));

    for ( i = 0; i <= k; i++ ) {
        C[i] = 0;
    }

    for ( j = 1; j <= n; j++ ) {
        C[A[j]]++;
    }

    for ( i = 1; i <=  k; i++ ) {
        C[i] = C[i] + C[i - 1];
    }

    for ( j = n ; j > 0; j-- ) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }

    free(C);

    return;
}

int main(void) {
    int i;
    int n;
    int k = 0;
    int *A, *B;

    scanf("%d\n", &n);
    A = malloc(sizeof(int) * (n + 1));
    B = malloc(sizeof(int) * (n + 1));

    for ( i = 1; i <= n; i++ ) {
        int d;
        scanf("%d", &d);
        A[i] = d;
        if ( d > k ) {
            k = d;
        }
        (void)fgetc(stdin);
    }

    CountingSort(A, B, n, k);

    for ( i = 1; i <= n; i++ ) {
        printf("%d", B[i]);
        if ( i < n ) {
            printf(" ");
        }
    }
    printf("\n");

    free(A);
    free(B);

    return 0;
}

