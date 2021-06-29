#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int N;
  int *A;
  int i, j, k;
  int v;

  scanf("%d", &N);
  A = (int *)malloc(sizeof(int) * N);

  for (i = 0; i < N; i++) scanf("%d", &A[i]);

  for (i = 0; i < N; i++) {
    if (i != N - 1) printf("%d ", A[i]);
    else printf("%d\n", A[i]);
  }

  for (i = 1; i < N; i++) {
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for (k = 0; k < N; k++) {
      if (k != N - 1) printf("%d ", A[k]);
      else printf("%d\n", A[k]);
    }
  }

  free(A);

  return 0;
}
