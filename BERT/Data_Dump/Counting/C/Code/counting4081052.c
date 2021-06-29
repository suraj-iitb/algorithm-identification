#include <stdio.h>
#include <stdlib.h>
#define VMAX 10000

void C(unsigned short *, unsigned short *, int);

int main(){
    unsigned short *A, *B;
    int n, i, j;

    scanf("%d", &n);

    A = malloc(sizeof(short)*n+1);
    B = malloc(sizeof(short)*n+1);

    /* your code */
    for(i = 0; i < n; i++){
        scanf("%hu",&A[i]);
    }

    C(A, B, n);

    for(j = 1; j < n; j++)
        printf("%u ",B[j]);
    printf("%u\n",B[j]);

  return 0;
}

void C(unsigned short *A, unsigned short *B, int n){
    int i, j;
    int C[VMAX+1];

    for(i = 0; i <= VMAX; i++)C[i] = 0;

    for(j = 0; j < n; j++)C[A[j]] = C[A[j]] + 1;

    for(i = 1; i <= VMAX; i++)C[i] = C[i] + C[i-1];

    for(j = n-1; j >= 0; j--){
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
}

