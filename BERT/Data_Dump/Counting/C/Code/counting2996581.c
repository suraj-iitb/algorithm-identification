#include<stdio.h>

#define ARRAYMAX 2000010

int A[ARRAYMAX], B[ARRAYMAX],C[10000];

void CountingSort(int max, int n){
    int i, j;

    for(i=0; i<max+1; i++){
        C[i]=0;
    }

    for(j=0; j<n; j++){
        C[A[j]]++;
    }

    for(i=1; i<max+1; i++){
        C[i] = C[i] + C[i-1];
    }

    for(j=n-1; j>=0; j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main(){
    int n, max;
    int i;

    max = 0;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &A[i]);
        if(A[i] > max) max = A[i];
    }

    CountingSort(max, n);

    for(i=1; i<n+1; i++){
        printf("%d", B[i]);
        if(i != n) printf(" ");
    }
    printf("\n");

    return 0;
}

