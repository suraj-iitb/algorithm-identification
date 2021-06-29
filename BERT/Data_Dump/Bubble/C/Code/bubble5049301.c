#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bubbleSort( int *, int );

int main()
{
  int N,array[MAX],i;

  scanf("%d",&N);
  if( N < 0 || N > MAX ) exit(1);
  
  for( i =0 ; i < N; i++ )
    {
      scanf(" %d",&array[i]);
      if( array[i] < 0 || array[i] > MAX )
	exit(2);
    }

  bubbleSort( array, N );

  return 0;
}

void bubbleSort( int *array, int N )
{
  int i,j,k,temp,count = 0;

  for( i = 0; i <= N-1; i++ )
    {
      for( j = N-1; j >= i+1; j-- )
	{
	  if( array[j] < array[j-1] )
	    {
	      temp = array[j];
	      array[j] = array[j-1];
	      array[j-1] = temp;
	      count++;
	    }
	}
    }

  for( k = 0; k < N; k++ )
    {
      if( k < N-1 )
	printf("%d ",array[k]);
      else
	printf("%d\n",array[k]);
    }
  printf("%d\n",count);
}
	   
	    
  

  

