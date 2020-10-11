#include <stdio.h>
#include <stdlib.h>

#define M 10000

int main(){
  int i, j, n, C[M + 1];
  int *A, *B;

  scanf("%d", &n);

  A = (int *)malloc(sizeof(int) * n + 1);
  B = (int *)malloc(sizeof(int) * n + 1);
  
  for(i = 0; i <= M; i++)
    C[i] = 0;

  for(i = 1; i <= n; i++){
    scanf("%d", &A[i]);
    C[A[i]]++;
  }
  
  for(i = 1; i <= M ; i++)
    C[i] = C[i] + C[i - 1];
  
  for(j = 1; j <= n; j++){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i = 1; i <= n; i++){
    if(i > 1)
      printf(" ");

    printf("%d", B[i]);
  }

  printf("\n");
}

  
  

