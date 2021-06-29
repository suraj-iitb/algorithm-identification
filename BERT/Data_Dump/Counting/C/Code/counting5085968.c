#include <stdio.h>
#define NMAX 2000000
#define KMAX 10000

void CountingSort(int *, int *, int, int);

int main(){
    int n, k = 0;
    int i;
    int A[NMAX];
    int B[NMAX];
    
    scanf("%d", &n);
    for(i = 0; i < n ; i++){
        scanf("%d", &A[i]);
        if(A[i] > k) k = A[i];
    }
    
    CountingSort(A, B, k, n);
    
    for(i = 1; i < n; i++) printf("%d ", B[i]);
    printf("%d\n", B[i]);
    
    return 0;
}

void CountingSort(int A[], int B[], int k, int n){
    int C[KMAX];
    int i, j;
    for(i = 0; i <= k; i++) C[i] = 0;
    
    for(j = 0; j < n; j++) C[A[j]]++;
    
    for(i = 1; i <= k; i++) C[i] += C[i-1];
    
    for(j = n-1; j >= 0; j--){
            B[C[A[j]]] = A[j];
            C[A[j]]--;
    }
}

