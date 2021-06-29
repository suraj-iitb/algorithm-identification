#include <stdio.h>
#include <stdlib.h>
#define A_MAX 10000

int main(){
    int *A, *B, C[A_MAX+1];
    int n, i;

    scanf("%d", &n);
    A = (int *)malloc((n+1) * sizeof(int));
    B = (int *)malloc((n+1) * sizeof(int));
    
    for ( i = 0; i <= A_MAX; i++ ) C[i] = 0;

    for ( i = 1; i <= n; i++ ){
        scanf("%d", &A[i]);
        C[A[i]]++;
    }

    for ( i = 1; i <= A_MAX; i++ ) C[i] = C[i] + C[i-1];

    for ( i = 1; i <= n; i++ ){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }

    for ( i = 1; i <= n; i++ ){
        if ( i > 1 ) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");
    free(A);
    free(B);
    return 0;
}
