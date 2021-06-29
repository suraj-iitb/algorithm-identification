#include <stdio.h>

int main()
{

  int i,j,count = 0,N,A[100],minj,swap,flag;

  scanf("%d",&N);
  for(i  = 0 ; i < N ; i++)scanf("%d",&A[i]);
  
  for(i = 0 ; i<N ; i++)
    {
      flag = 0;
      minj = i;
      for(j= i ; j <N ; j++)
	{
	  if( A[j] < A[minj] )
	    {
	      minj = j;
	      flag = 1;
	    }
	}
      if(flag == 1)
	{
	  count++ ;
	  swap = A[i];
	  A[i] = A[minj];
	  A[minj] = swap;
	}
    }

  for(i = 0 ; i < N ; i++)
    {
      if(i == N - 1)
	{
	  printf("%d\n%d\n" , A[i] , count);
	  break;
	}
      printf("%d ",A[i]);
    }

}

