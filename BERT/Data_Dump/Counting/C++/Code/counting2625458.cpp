#include <cstdio>
#include <cstdlib>
#define MAX 2000001
#define VMAX 10000
 
int main() {
    unsigned short *A, *B;
    int n, i, j;
    int C[VMAX];
    scanf("%d", &n);
    A = (unsigned short *)malloc(sizeof(short) * n + 1);
    B = (unsigned short *)malloc(sizeof(short) * n + 1);
 
    for (int i=0; i<VMAX; i++) C[i] = 0;
 
    for (int i=0; i<n; i++) {
        scanf("%hu", &A[i + 1]);
        C[A[i + 1]]++;
    }
 
    for (i=1; i<=VMAX; i++) C[i] = C[i] + C[i-1];
 
    for (j=1; j<=n; j++) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
    for (int i=1; i<=n; i++) {
        printf("%d", B[i]);
        if (i == n) printf("\n");
        else printf(" ");
    }
    return 0;
}
