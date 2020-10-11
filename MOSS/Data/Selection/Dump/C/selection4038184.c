#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i, j, minj, N, *A, temp, count=0;

  scanf("%d", &N);

  A = malloc( N * sizeof(int));

  for( i=0; i<N; i++ ) scanf("%d", &A[i]);
    
  for( i=0; i<N; i++ )
    {
      minj = i;

      for( j=i; j<N; j++ )
	{
	  if( A[j] < A[minj] ) minj = j;
	}

      if( minj != i)
	{
	  temp = A[i];
	  A[i] = A[minj];
	  A[minj] = temp;
	  count++;
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

  free( A );

  return 0;
}

  

