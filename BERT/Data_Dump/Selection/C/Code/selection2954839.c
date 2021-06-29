#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i,j,n,minij,hold,count=0;
  int array[100];

  scanf("%d",&n);
  if( n < 1 || n > 100 )
    exit(1);

  for( i = 0; i < n; i++ )
    {
      scanf("%d",&array[i]);
      if( array[i] < 0 || array[i] > 100 )
	exit(1);
    }

  for( i= 0; i < n-1; i++ )
    {
      minij = i;
      for( j = i; j < n; j++ )
	{
	  if( array[j] < array[minij] )
	    minij = j;
	}
      hold = array[i];
      array[i] = array[minij];
      array[minij] = hold;
      if( array[i] != array[minij] )
	count++;
    }
  for( i = 0; i < n-1; i++ )
    printf("%d ",array[i]);
  printf("%d\n%d\n",array[n-1],count);

  return 0;
}

