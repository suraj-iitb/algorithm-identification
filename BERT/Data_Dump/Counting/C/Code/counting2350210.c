#include <stdio.h>
 
 #define MAX 2000001

void Counting_Sort(int A[], int B[], int n, int k) {
    int i, j;
    int C[10001];
    for(i = 0; i <= k; ++i){
        C[i] = 0;
    }
    for(j = 1; j <= n; ++j){
        C[A[j]] = C[A[j]]+1;
    }
    for(i = 1; i <= k; ++i){
        C[i] = C[i] + C[i-1];
    }

    for(j = n; j >= 1; --j) {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]]-1;
    }
}

int A[MAX], B[MAX];

int main() {
    int i, n;
    int k = 0;

    scanf("%d", &n);
    for(i = 1; i <= n; ++i) {
        scanf("%d", A + i);
        k = A[i] > k ? A[i] : k;
    }

    Counting_Sort(A, B, n, k);
    for(i = 1; i <= n; ++i) {
        if(i-1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");
    return 0;
}
