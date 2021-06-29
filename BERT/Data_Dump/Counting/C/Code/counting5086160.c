#include <stdio.h>
#include <stdlib.h>
#define k 10000
int main()
{
  int n,i,j;
  int *A,*B, C[k];
  scanf("%d", &n);
  
  A = malloc((n+1) * sizeof(int));
  B = malloc((n+1) * sizeof(int));
  
  for(i = 1; i <= n; i++)
    {
      scanf("%d", &A[i]);
    }
  //countingsort
  for(i = 0; i <= k; i++)
    {
      C[i] = 0;
    }
  for(j = 1; j <= n; j++)
    {
      C[A[j]]++;
    }

  for(i = 1; i <= k; i++)
    {
      C[i] = C[i] + C[i-1];
    }

  for(j = n; j >= 1; j--)
    {
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }

  
  for(i = 1; i <= n; i++)
    {
      printf("%d", B[i]);
      if(i == n)
	printf("\n");
      else
	printf(" ");
    }
  free(A);
  free(B);
  return 0;
}

