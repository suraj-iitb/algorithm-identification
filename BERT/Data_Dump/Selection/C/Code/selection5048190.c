#include <stdio.h>

int main()
{
  int N, A[100], i, j, key, num=0, minj;

  scanf("%d",&N);
  for(i = 0; i < N; i++)
    {
      scanf("%d",&A[i]);
    }

  for(i = 0; i < N; i++)
    {
      minj = i;
      for(j = i; j < N; j++)
	{
	  if(A[j] < A[minj])
	    {
	      minj = j;
	    }
	}
      if(A[i] != A[minj])
	{
	  key = A[i];
	  A[i] = A[minj];
	  A[minj] = key;
	  num++;
	}
    }

  for(i = 0; i < N; i++)
    {
      printf("%d",A[i]);
      if(i != N-1)printf(" ");
    }
  printf("\n%d\n",num);

  return 0;
}

