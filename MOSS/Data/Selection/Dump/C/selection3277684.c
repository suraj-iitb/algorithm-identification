#include <stdio.h>

int main()
{
  int i,j,minj,A[100],N,count=0,c;

  scanf("%d",&N);

  if(N < 1 || N > 100) return 0;

  for( i = 0 ; i < N ; i++ )
    {
      scanf("%d",&A[i]);
    }

  for( i = 0 ; i <= N-1 ; i++ )
    {
      minj = i;
      for( j = i ; j <= N-1 ; j++ )
	{
	  if(A[j] < A[minj])
	    {
	      minj = j;
	    }
	}
      if(i != minj)
	{
	  c = A[i];
	  A[i] = A[minj];
	  A[minj] = c;
	  count++;
	}
    }

  for(i = 0 ; i < N ; i++ )
    {
      printf("%d",A[i]);
      if(i < N-1) printf(" ");
    }
  
  printf("\n");
  
  printf("%d\n",count);
  
  return 0;
}

