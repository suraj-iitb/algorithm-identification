 #include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define k 10000

/*
*
*/

void countingSort(int A[], int n, int B[]);

int main(int argc, char** argv) {
int *A, *B, n;
scanf("%d", &n);

A = (int *)malloc(sizeof(int) * n+1);
B = (int *)malloc(sizeof(int) * n+1);
for (int i = 0; i < n; ++i) scanf("%d", &A[i+1]);

countingSort(A, n, B);

for (int x = 1; x <= n; ++x)
{
if (x > 1) printf(" ");
printf("%d", B[x]);
}
printf("\n");

return (EXIT_SUCCESS);
}

void countingSort(int A[], int n, int B[])
{
int C[k+1];
for (int ix = 0; ix <= k; ++ix) C[ix] = 0;
for (int jx = 0; jx < n; ++jx) C[A[jx+1]]++;
for (int kx = 1; kx <= k; ++kx) C[kx] += C[kx-1];
for (int w = 1; w <= n; ++w)
{
B[C[A[w]]] = A[w];
C[A[w]]--;
}
}
