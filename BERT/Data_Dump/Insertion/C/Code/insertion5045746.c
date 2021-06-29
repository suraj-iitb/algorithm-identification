#include <stdio.h>
#include <stdlib.h>

#define N_MAX 100

void insertionSort( int *, int );

int main()
{
  int N,i;
  int array[N_MAX];

  scanf("%d",&N);
  if( N < 0 || N > N_MAX ) exit(1);
  for( i = 0; i < N; i++ )
    {
      scanf(" %d",&array[i]);
      if( array[i] > 1000 || array[i] < 0 ) exit(2);
    }

  for( i = 0; i < N; i++ )
    {
      if( i < N-1 )
	printf("%d ",array[i]);
      else
	printf("%d\n",array[i]);
    }
 

  insertionSort( array, N );

  return 0;
}

void insertionSort( int *array, int N )
{
  int i,j,k,temp;

  for( i = 1; i <= N-1; i++ )
    {
      temp = array[i];
      j = i - 1;
      while( j >= 0 && array[j] > temp )
	{
	  array[j+1] = array[j];
	  j--;
	}
      array[j+1] = temp;
      
      for( k = 0; k < N; k++ )
	{
	  if( k < N-1 )
	    printf("%d ",array[k]);
	  else
	    printf("%d\n",array[k]);
	}
    }
       
}

