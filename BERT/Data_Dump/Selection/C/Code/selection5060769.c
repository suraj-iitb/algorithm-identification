#include <stdio.h>
#include <stdlib.h>

#define N 100

void selectionSort( int * , int );

int main()
{
  int n,array[N],i;

  scanf("%d",&n);
  if( n < 1 || n > N ) exit(1);

  for( i = 0; i < n; i++ )
    {
      scanf("%d",&array[i]);
      if( array[i] < 0 || array[i] > N ) exit(2);
    }

  selectionSort( array, n );

  return 0;
}

void selectionSort( int *array, int n )
{
  int i,j,k,temp,minj,count = 0;

  for( i = 0; i <= n-2; i++ )
    {
      minj = i;
      for( j = i; j <= n-1; j++ )
	{
	  if( array[j] < array[minj] )
	    minj = j;
	}
      temp = array[i];
      array[i] = array[minj];
      array[minj] = temp;

      if( i != minj )
	count++;
    }
  
  for( k = 0; k < n; k++ )
    {
      if( k < n-1 )
	printf("%d ",array[k]);
      else
	printf("%d\n",array[k]);
    }

  printf("%d\n",count);
}

