#include <stdio.h>
#include <stdlib.h>
#define N 2000001
#define K 10000

int main(){
  int *A, *B;
  int C[K+1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);

  for(i = 1; i <= n; i++){
    scanf("%d", &A[i]);
  }

  for(i = 0; i <= K; i++){
    C[i] = 0;
  }

  for(j = 1; j <= n; j++){
    C[A[j]]++;
  }

  for(i = 1; i <= K; i++){
    C[i] =  C[i] + C[i-1];
  }

  for(j = n; j >= 1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i = 1; i <= n; i++){
    printf("%d", B[i]);
    if(i == n)break;
    printf(" ");
  }
  printf("\n");

  return 0;
}
