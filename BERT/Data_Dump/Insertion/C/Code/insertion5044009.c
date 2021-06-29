#include <stdio.h>

int main() {
    int i, j, k, v, N;
    int A[100];
    
    scanf("%d", &N);
    for ( i = 0; i < N; i++) {
        scanf(" %d", &A[i]);
    }
    for ( k = 0; k <= N - 1; k++) {
        printf("%d", A[k]);
        if ( k != N - 1) printf(" ");
        if ( k == N - 1) printf("\n");
    }
    
    for ( i = 1; i <= N - 1; i++) {
        v = A[i];
        j = i - 1;
        while ( j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        
        for ( k = 0; k <= N - 1; k++) {
            printf("%d", A[k]);
            if ( k != N - 1 ) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
