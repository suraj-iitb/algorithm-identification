#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define K 10000

int main(){
  unsigned int *A, *B;

  int C[K+1];
  int n, i, j;
  scanf("%d", &n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);

  for ( i = 0; i <= K; i++ ){
    C[i] = 0;
  }

  for ( i = 0; i < n; i++ ){
    scanf("%d", &A[i + 1]);
    C[A[i + 1]]++;
  }

  for ( i = 1; i <= K; i++ ){
    C[i] = C[i] + C[i - 1];
  }

  for ( j = 1; j <= n; j++ ){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for ( i = 1; i <= n-1; i++ ){
    printf("%d ", B[i]);
  }
  printf("%d\n",B[n]);

  return 0;
}
