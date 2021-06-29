#include <stdio.h>

#define MAX 200001
#define MAXV 10001

int main(){
  int *A, *B;

  int i, n;
  int C[MAXV];

  scanf("%d", &n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);

  for(i = 0; i <= MAXV; i++)
    C[i] = 0;

  for(i = 0; i < n; i++){
    scanf("%d", &A[i+1]);
    C[A[i+1]]++;
  }

  for(i = 1; i <= MAXV; i++)
    C[i] += C[i-1];

  for(i = 1; i <= n; i++){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

  for(i = 1; i <= n; i++){
    if(i > 1)
      printf(" ");
    printf("%d", B[i]);
  }

  printf("\n");

  return 0;
}
