#include <stdio.h>

int main()
{
  int flag,i,j,c,count=0,N,A[100];

  flag = 1;

  scanf("%d",&N);

  if(N < 1 || N > 100) return 0;

  for( i = 0 ; i < N ; i++ )
    {
      scanf("%d",&A[i]);
    }
  
  while(flag)
    {
      flag = 0;
      for( j = N-1 ; j >= 1  ; j--)
	{
	  if(A[j] < A[j-1])
	    {
	      c = A[j];
	      A[j] = A[j-1];
	      A[j-1] = c;
	      flag = 1;
	      count++;
	    }
	}
    }

  for( i = 0 ; i < N ; i++ )
    {
      printf("%d",A[i]);
      if(i < N-1) printf(" ");
    }
  printf("\n");

  printf("%d\n",count);
  

  return 0;
}

