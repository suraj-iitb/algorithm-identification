#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define CMAX 10000

int A[MAX], B[MAX];

void countsort(int A[], int n, int B[], int k) {
    int C[k+1];
    for (int i = 0; i <= k; i++)  C[i] = 0;
    for (int i = 1; i <= n; i++)  C[A[i]]++;
    for (int i = 1; i <= k; i++) C[i] = C[i] + C[i-1];
    for (int i = n; i >= 1; i--) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }

}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    int k = A[1];
    for ( int i = 2; i <= n; i++) {
        if (A[i] >= k) {
            k = A[i];
        }
    }
    countsort(A, n, B, k);

    for ( int i = 1; i <= n; i++){
        if (i != 1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");
    return 0;
}


