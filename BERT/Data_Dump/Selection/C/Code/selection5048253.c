#include <stdio.h>

int main() {
    int i, j, minj, n, A[100], tmp, cnt = 0;
    
    scanf("%d", &n);
    
    for( i=0; i<n; i++ ) {
        scanf(" %d", &A[i]);
    }
    
    for ( i=0; i<n; i++ ) {
        minj = i;
        for( j=i; j<n; j++ ) {
            if( A[j] < A[minj] ) {
                minj = j;
            }
        }
        if ( i != minj ) cnt++;
        tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
    }
    
    for ( i=0; i<n; i++ ) {
        if (i != n-1) printf("%d ", A[i]);
        if (i == n-1) printf("%d\n", A[i]);
    }
    printf("%d\n", cnt);
    
    return 0;
}
