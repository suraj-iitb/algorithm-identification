#include<stdio.h>
int main()
{
  int i,j,k,N,A[100],count=0;
  
  scanf("%d",&N);
  
  for(i = 0; i < N; i++) scanf("%d",&A[i]);
  
  for(i = 0; i < N-1; i ++)
    {
      for(j = N-1; j > i; j--)
	{
	  if(A[j] < A[j-1])
	    {
	      k = A[j];
	      A[j] = A[j-1];
	      A[j-1] = k;
	      count++;
	    }
	}
    }
  for(i = 0; i < N; i ++)
    {
      if(i == N-1)
	{
	  printf("%d",A[i]);
	  break;
	}
      printf("%d ",A[i]);
    }
  printf("\n%d\n",count);
  return 0;
}
