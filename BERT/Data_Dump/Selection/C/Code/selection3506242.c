#include<stdio.h>

int Sort(int A[], int N) {
  int i, j, t, sr, ij;
  sr = 0;
  for (i = 0; i < N - 1; i++) {
    ij = i;
    for (j = i; j < N; j++) {
      if (A[j] < A[ij])ij = j;
    }
    t = A[i]; A[i] = A[ij]; A[ij] = t;
    if (i != ij)sr++;
  }
  return sr;
}

int main() {
  int A[100], N, i, sr;

  scanf("%d", &N);
  for (i = 0; i < N; i++) scanf("%d", &A[i]);

  sr = Sort(A, N);

  for (i = 0; i < N; i++) {
    if (i > 0)printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n",sr);

  return 0;
}
