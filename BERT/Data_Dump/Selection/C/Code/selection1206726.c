#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int N, i, j;
  int *A;
  int minj, tmp, ct = 0;

  scanf("%d", &N);

  A = (int *)malloc(sizeof(int) * N);

  for (i = 0; i < N; i++) scanf("%d", &A[i]);

  for (i = 0; i < N; i++) {
    minj = i;
    for (j = i; j < N; j++) {
      if (A[j] < A[minj]) minj = j;
    }
    if (i != minj) {
      tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      ct++;
    }
  }

  for (i = 0; i < N; i++) {
    if (i != N - 1) printf("%d ", A[i]);
    else printf("%d\n", A[i]);
  }
  printf("%d\n", ct);

  free(A);

  return 0;
}
