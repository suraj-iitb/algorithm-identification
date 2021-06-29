#include <stdio.h>
#include <stdlib.h>
#define N 2000001

int main()
{
  int n, C[10001]={0}, i, j;
  unsigned short *A, *B;

  scanf("%d",&n);
  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
  for(i = 1; i <= n; i++)
    {
      scanf("%d",&A[i]);
      C[A[i]]++;
    }
  for(i = 1; i <= 10000; i++)
    {
      C[i] = C[i] + C[i-1];
    }
  
  for(j = n;j > 0; j--)
    {
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }
  for(i = 1; i <= n; i++)
    {
      printf("%d",B[i]);
      if(i != n)printf(" ");
    }
  printf("\n");

  return 0;
}

