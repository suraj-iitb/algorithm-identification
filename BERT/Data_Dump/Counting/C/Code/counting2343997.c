#include <stdio.h>
#include <stdlib.h>
#define N 200001
#define K 10001

int main() {
  int n, i, C[K];
  int *A, *B;

  for(i = 0; i < K; i++) {
    C[i] = 0;
  }

  scanf("%d", &n);
  A = (int*)malloc(sizeof(int) * n + 1);
  B = (int*)malloc(sizeof(int) * n + 1);
  for(i = 0; i < n; i++) {
    scanf("%d", &A[i+1]);
    C[A[i+1]]++;
  }

  for(i = 1; i < K; i++) {
    C[i] = C[i] + C[i-1];
  }
  for (i = 1; i <= n; i++) {
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

  for (i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");

  free(A);
  free(B);
  return 0;
}
