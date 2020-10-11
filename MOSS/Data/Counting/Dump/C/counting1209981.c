#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int n, k = -1, i, j;
  int *A, *B, *C;

  scanf("%d", &n);
  A = (int *)malloc(sizeof(int) * n);
  B = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
    k = (int)fmax(k, A[i]);
    B[i] = 0;
  }
  C = (int *)malloc(sizeof(int) * (k + 1));

  for (i = 0; i <= k; i++) C[i] = 0;
  for (i = 0; i < n; i++) C[A[i]]++;
  //for (i = 1; i <= k; i++) C[i] += C[i-1];
  j = 0;
  while (C[j] == 0) j++;
  for (i = 0; i < n; i++) {
    B[i] = j;
    C[j]--;
    while (C[j] == 0) j++;
  }

  for (i = 0; i < n; i++) {
    if (i != n - 1) printf("%d ", B[i]);
    else printf("%d\n", B[i]);
  }

  return 0;
}
