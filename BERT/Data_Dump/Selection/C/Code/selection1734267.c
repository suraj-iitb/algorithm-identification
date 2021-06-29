#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int main()
{
  int N,A[MAX],i,j,minj,count=0,temp,k;

  scanf("%d",&N);
  if( N < 1 || MAX < N ) exit(2);

  for( i = 0 ; i < N ; i++ )
    {
      scanf("%d",&A[i]);
      if( A[i] < 0 || MAX < A[i] ) exit(3);
    }

  for( i = 0 ; i < N ; i++ )
    {
      minj=i;
      for( j = i+1 ; j < N ; j++ )
	{
	  if( A[j] < A[minj] )
	    minj = j;
	}
      if( i != minj )
	{
      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
      count++;
	}
 }


  for( i = 0 ; i < N-1 ; i++ )
    {
      printf("%d ",A[i]);
    }
  printf("%d\n%d\n",A[i],count); 


  return 0;
}
