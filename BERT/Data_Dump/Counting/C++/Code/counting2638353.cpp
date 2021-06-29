#include <iostream>
#include <stdio.h>

#define MAX 2000001
#define vMAX 10000


int main() {
    int n;
    int C[vMAX];
    for (int i = 0; i < vMAX; i++) C[i] = 0;
    
    scanf("%d", &n);
    int *A = new int[n+1];
    int *B = new int[n+1];
    
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        C[A[i]] += 1;
    }
    
    for (int i = 1; i < vMAX; i++) {
        C[i] = C[i] + C[i-1];
    }
    
    for (int i = n; i >= 1; i--) {
        B[C[A[i]]] = A[i];
        C[A[i]] --;
    }
    
    for (int i = 1; i <=n; i++) {
        if (i > 1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");
    delete [] A;
    delete [] B;
    return 0;
}
