#include <stdio.h>
#include <stdlib.h>
#define N 10000

int  main()
{
  int i,j,n,*A,*B,C[N + 1];

  scanf("%d",&n);
  A = malloc(sizeof(int) * n + 1);
  B = malloc(sizeof(int) * n + 1);
  
  for(i = 0;i < n;i++) scanf("%d",&A[i]);

  for(i = 0;i < 10000;i++) C[i] = 0;

  for(j = 0;j < n;j++) C[A[j]]++;

  for(i = 1;i < 10000;i++) C[i] = C[i] + C[i - 1];

  for(j = n;j >= 0;j--)
    {
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }

  for(i = 1;i <= n;i++)
    {
      if(i > 1) printf(" ");
      printf("%d",B[i]);
    }
  printf("\n");

  return 0;
}

