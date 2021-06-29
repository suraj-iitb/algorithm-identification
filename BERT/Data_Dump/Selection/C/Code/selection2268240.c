#include <stdio.h>

int main()
{
  int N, A[100];
  int i, j, minj, tmp, flag, counter = 0;

  scanf("%d", &N);
  for(i = 0; i < N; i++)
    {
      scanf("%d", &A[i]);
    }

  for(i = 0; i <= N-1; i++)
    {
      flag = 0;
      minj = i;
      for(j = i; j <= N-1; j++)
	{
	  if(A[j] < A[minj])
	    {
	      minj = j;
	      flag++;
	    }
	}
      if(flag != 0)
	{
	  tmp = A[minj];
	  A[minj] = A[i];
	  A[i] = tmp;
	  counter++;
	}
    }
  for(i = 0; i < N; i++)
    {
      printf("%d", A[i]);
      if(i != N-1) printf(" ");
    }
  printf("\n");
  printf("%d\n", counter);

  return 0;
}
