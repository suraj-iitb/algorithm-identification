#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i, j, N, *A, flag, temp, count=0;

  scanf("%d", &N);

  A = malloc( N * sizeof(int));

  flag = 1;

  for( i=0; i<N; i++ ) scanf("%d", &A[i]);

  while(flag==1)
    {
      flag = 0;

      for( j=N-1; j>0; j-- )
	{
	  if( A[j] < A[j-1] )
	    {
	      temp = A[j];
	      A[j] = A[j-1];
	      A[j-1] = temp;
	      flag = 1;
	      count++;
	    }
	}
    }

  for( i=0; i<N; i++ )
    {
      printf("%d", A[i]);
      if( i == N-1 )
	{
	  printf("\n");
	  break;
	}
      printf(" ");
    }

  printf("%d\n", count);

  return 0;
}
  

