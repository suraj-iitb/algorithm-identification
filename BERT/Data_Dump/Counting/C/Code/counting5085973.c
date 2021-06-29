#include <stdio.h>

int main() {
    int i,j,k=-1;
    int n;
      int A[2000005];
    int B[2000000];
    int C[10000];
    
    scanf("%d", &n);
    for ( i=1; i<=n; i++) {
        scanf("%d", &A[i]);
        if ( A[i] > k )
            k = A[i];
    }
    for ( i=0; i<=k; i++) {
        C[i] = 0;}
    for ( j=1; j<=n; j++ ) {
        C[A[j]]++;}
    for ( i=1; i<=k; i++ ) {
        C[i] = C[i] + C[i-1];}
    for ( j=n; j>0; j-- ) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;}
    for ( i=1; i<=n; i++ ) {
        printf("%d", B[i]);
        if ( i != n )
            printf(" ");
        else if ( i == n )
            printf("\n");
    }
    return 0;
}

