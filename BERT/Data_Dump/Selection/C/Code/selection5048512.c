#include<stdio.h>

int main()
{
  int N,A[100],i,j,swap,count=0,minj;

  scanf("%d",&N);
  for(i=0; i<N;i++)scanf("%d",&A[i]);

  for(i=0; i < N-1; i++)
    {
      minj = i;
      for(j=i; j < N; j++)
	{
	  if(A[j] < A[minj]) minj = j;
	}
      if(minj != i)
	{
	  swap = A[minj];
	  A[minj] = A[i];
	  A[i] = swap;
	  count++;
	}
    }

  for(i=0; i < N; i++)
    {
      if(i > 0)printf(" ");
      printf("%d",A[i]);
    }
  printf("\n%d\n",count);

  return 0;
}

