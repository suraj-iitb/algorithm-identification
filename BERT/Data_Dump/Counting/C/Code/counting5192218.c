#include<stdio.h>

int n;

void CountingSort(int A[], int B[], int k){
    int i, j;
    int C[k+1];
    for(i = k; i >= 0; i--){
        C[i] = 0;
    }
    for(j = 1; j <= n;j++){
        C[A[j]]++;
    }
    
    for(i = 1; i <= k; i++){
        C[i] = C[i] + C[i-1];
    }
    for( j = n; j > 0;j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main(){
    scanf("%d", &n);
    int i;
    int A[n+1], B[n+1];
    for(i = n; i >= 1; i--){
        scanf("%d", &A[i]);
    }
    int k = 10000;
    CountingSort(A, B, k);
    for(i = 1; i <= n; i++){
        if(i != 1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");

    return 0;
}
