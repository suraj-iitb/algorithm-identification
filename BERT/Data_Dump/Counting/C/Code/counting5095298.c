#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

int main(){
    int *A, *B;
    int C[MAX+1];
    int n, i, j;

    scanf("%d",&n);

    A = malloc( sizeof(int) * n+1 );
    B = malloc( sizeof(int) * n+1 );
    for(i=0; i<n; i++) scanf("%d",&A[i]);
    for(i=0; i<=MAX; i++) C[i] = 0;

    for(j=0; j<n; j++) C[A[j]]++;

    for(i=0; i<MAX; i++) C[i+1] += C[i];

    for(j=n; j>=0; j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }

    for(i=1; i<n; i++) printf("%d ",B[i]);
    printf("%d\n",B[n]);

    return 0;
}
