#include <stdio.h>

int main() {
    int i, n, A[100], tmp, cnt = 0, flag = 1;
    
    scanf("%d", &n);
    
    for( i=0; i<n; i++ ) {
        scanf(" %d", &A[i]);
    }
    while( flag ) {
        flag = 0;
        for ( i=n-1; i>=1; i-- ) {
            if ( A[i] < A[i-1] ) {
                tmp = A[i];
                A[i] = A[i-1];
                A[i-1] = tmp;
                flag = 1;
                cnt++;
            }
        }
    }
    for( i=0; i<n; i++ ) {
        if (i != n-1) printf("%d ", A[i]);
        if (i == n-1) printf("%d\n", A[i]);
    }
    printf("%d\n", cnt);
    
    return 0;
}
