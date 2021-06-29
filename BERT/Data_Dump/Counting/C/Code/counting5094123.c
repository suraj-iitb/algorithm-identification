#include <stdio.h>
#include <stdlib.h>

#define N 2000001
#define MAX 10000

int main()
{
  int i, j, n, k = 0;
  int *A, *B, *C;
  
  scanf("%d", &n);

  A = (int *)malloc(sizeof(int) * (n + 1));
  
  for(i = 1 ; i < n + 1 ; i++)
    {
      scanf("%d", &A[i]);
      if(A[i] > k) k = A[i];
    }

  C = (int *)malloc(sizeof(int) * (k + 1));
  
  for(i = 0 ; i < k + 1 ; i++)
    {
      C[i] = 0;
    }

  for(j = 1 ; j < n + 1 ; j++)
    {
      C[A[j]] = C[A[j]] + 1;
    }

  for(i = 1 ; i < k + 1 ; i++)
    {
      C[i] = C[i] + C[i - 1];
    }

  B = (int *)malloc(sizeof(int) * (n + 1));
  
  for(j = n + 1 ; j > 0 ; j--)
    {
      B[C[A[j]]] = A[j];
      C[A[j]] = C[A[j]] - 1;
    }

  free(A);
  free(C);

  for(i = 1 ; i < n ; i++)
    {
      printf("%d ", B[i]);
    }
  printf("%d\n", B[i]);

  free(B);
  
  return 0;
}
  

