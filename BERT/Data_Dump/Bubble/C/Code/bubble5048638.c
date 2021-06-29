#include <stdio.h>
#include <stdlib.h>

int main()
{
  int N, i, j, tmp, *A, flag;

  scanf("%d", &N);
  if(N < 1 || N > 100) exit(1);

  A = (int *)malloc(N * (sizeof(int)));

  for(i = 0 ; i < N ; i++)
    {
      scanf("%d", &A[i]);
      if(A[i] < 0 || A[i] > 100) exit(2);
    }

  i = 0;
  flag = 1;
  while(flag == 1)
    {
      flag = 0;

      for(j = N - 1 ; j >= 1 ; j--)
	{
	  if(A[j] < A[j - 1])
	    {
	      tmp = A[j];
	      A[j] = A[j - 1];
	      A[j - 1] = tmp;
	      i++;
	      flag = 1;
	    }
	}
    }

  for(j = 0 ; j < N - 1 ; j++)
    {
      printf("%d ", A[j]);
    }
  printf("%d\n%d\n", A[j], i);
	  
  free(A);

  return 0;
}

