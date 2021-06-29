#include <stdio.h>
#include <stdlib.h>

int main(){
  int i, n, k = 10000;
  int *A, *B, C[k+1];

  scanf("%d", &n);

  A = (int *)malloc((n+1) * sizeof(int));
  B = (int *)malloc((n+1) * sizeof(int));

  for(i = 1; i <= n; i++) scanf("%d", &A[i]);

  for(i = 0; i <= k; i++) C[i] = 0;

  for(i = 1; i <= n; i++) C[A[i]]++;

  for(i = 1; i <= k; i++) C[i] = C[i] + C[i-1];

  for(i = n; i >= 1; i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

  for(i = 1; i < n; i++) printf("%d ", B[i]);

  printf("%d\n", B[n]);

  return 0;
}

