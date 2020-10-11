#include <stdio.h>

int main()
{

  int i, j , flag = 0 , count = 0,A[100],swap,N;

  scanf("%d",&N);
  for(i = 0 ; i<N ; i++) scanf("%d",&A[i]);
    
  for(i = 0;i <N; i++)
    {
      for(j = N-1 ; j >i ; j--)
	{
	  
	  if (A[j] < A[j -1]  )
	    {
	      swap = A[j];
	      A[j] = A[j -1];
	      A[j -1] = swap;
	      count++;
	    }
	  
	}

    }
  for(i =0 ; i <N ; i++)
    {
      if(i ==  N-1)
	{
	  printf("%d\n%d\n",A[i],count);
	  break;
	}
      printf("%d " , A[i]);
    }
}

