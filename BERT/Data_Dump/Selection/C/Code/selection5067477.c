#include <stdio.h>

int main()
{
  int A[100], i, j, N, minj, store, count = 0;

  scanf("%d", &N);
  for(i=0; i <= N-1; i++)
    {
      scanf("%d", &A[i]);
    }
  
  for(i = 0; i < N-1; i++)
    {
      minj = i;
      for(j = i; j <= N-1; j++)
	{
	  if (A[j] < A[minj])
	    {
	      minj = j;
	    } 
	}
      if(A[i] != A[minj])
	{
	count++;
	}
      store = A[i];
      A[i] = A[minj];
      A[minj] = store;
    }
  for(i = 0; i <= N-1; i++)
    {
      printf("%d", A[i]);
      if (i == N-1)
	printf("\n");
      else
	printf(" ");
    }
  printf("%d\n", count);
  return 0;
}

