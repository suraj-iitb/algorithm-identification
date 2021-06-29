#include <stdio.h>
#include <stdlib.h>

#define N 2000000
#define K 10000

int main(void){
    int i, n, C[K + 1];
    unsigned short *A, *B;
    
    scanf("%d", &n);
    
    A = malloc(sizeof(short)*n+1);
    B = malloc(sizeof(short)*n+1);
    
    for (i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    
    for (i = 0; i <= K; i++) {
        C[i] = 0;
    }
    
    for (i = 1; i <= n; i++) {
        C[A[i]]++;
    }
    
    for (i = 1; i <= K; i++) {
        C[i] += C[i - 1];
    }
    
    for (i = n; i >= 1; i--) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
    
    for (i = 1; i < n; i++) {
        printf("%d ", B[i]);
    }
    printf("%d\n", B[i]);
    
    return 0;
}


