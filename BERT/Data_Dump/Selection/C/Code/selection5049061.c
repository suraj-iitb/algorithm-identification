#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, j, minj, cnt = 0;
  int *A, N, tmp;

  scanf("%d", &N);
  if(N < 1 || 100 < N) exit(1);

  A = (int *)malloc(sizeof(int) * N);

  for(i = 0 ; i < N ; i++)
    {
      scanf("%d", &A[i]);
      if(A[i] < 0 || 100 < A[i]) exit(2);
    }

  for(i = 0 ; i <= N - 1 ; i++)
    {
      minj = i;

      for(j = i ; j <= N - 1 ; j++)
	{
	  if(A[j] < A[minj])
	    {
	      minj = j;
	    }
	}

      if(minj != i)
	{
	  tmp = A[i];
	  A[i] = A[minj];
	  A[minj] = tmp;
	  cnt++;
	}
    }

  for(i = 0 ; i < N - 1 ; i++)
    {
      printf("%d ", A[i]);
    }
  printf("%d\n%d\n", A[i], cnt);

  free(A);
  
  return 0;
}

