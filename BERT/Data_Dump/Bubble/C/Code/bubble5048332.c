#include<stdio.h>

int main()
{
  int A[100],N,i,j,swap,count=0;

  scanf("%d",&N);
  for(i=0; i < N; i++)scanf("%d",&A[i]);

  for(i=0; i < N; i++)
    {
      for(j=N-1; j >= i+1; j--)
	{
	  if(A[j] < A[j-1])
	  {
	    swap = A[j-1];
	    A[j-1] = A[j];
	    A[j] = swap;
	    count++;
	  }
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

  
  
  

