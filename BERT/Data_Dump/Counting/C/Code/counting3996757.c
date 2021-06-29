#include<stdio.h>
#include<stdlib.h>
#define VMAX 10000

int main(){
    unsigned short *A, *B;
    int C[VMAX + 1];
    int n, i;

    scanf("%d", &n);

    A = malloc(sizeof(short) * n + 1);
    B = malloc(sizeof(short) * n + 1);

    for(i = 0; i <= VMAX; i++) C[i] = 0;
    for(i = 0; i < n; i++){
        scanf("%hu", &A[i + 1]);
        C[A[i + 1]]++;
    }
    for(i = 1; i <= VMAX; i++) C[i] = C[i] + C[i - 1];
    for(i = n; i >= 1; i--){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
    for(i = 1; i <= n; i++){
        if(i > 1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");

    free(A);
    free(B);

    return 0;
}