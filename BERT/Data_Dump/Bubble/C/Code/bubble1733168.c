#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int main()
{
  int N;
  int A[MAX];
  int temp,i,j,flag=1,count=0;

  scanf("%d",&N);  
if( N < 1 || MAX < N ) exit(2); 

  for( i = 0 ; i < N ; i++ )
    {
      scanf("%d",&A[i]);
      if( A[i] < 0 || MAX < A[i] ) exit(3);
    }

  i = 0;
  while( flag != 0 )
    {
      flag = 0;
      for( j = N-1 ; j >= i+1 ; j-- )
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
      i++;
    }
    
      for( i = 0 ; i < N-1 ; i++ )  printf("%d ",A[i]);
      
      printf("%d\n%d\n",A[i],count);

      return 0;
    }
