#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i,j,n,hold,count=0;
  int Array[100];
  
  scanf("%d",&n);
  if( n < 1 || n > 100 )
    exit(1);
  
  for( i = 0; i < n; i++ )
    {
      scanf("%d",&Array[i]);
      if( Array[i] < 0 || Array[i] > 100 )
	exit(1);	
    }
  
  for( i = 0; i < n-1; i++ )
    {
      for( j = n-1; j > i; j-- )
	{
	  if(Array[j] < Array[j-1])
	    {
	      hold = Array[j];
	      Array[j] = Array[j-1];
	      Array[j-1] = hold;
	      count++;
	    }
	}
    }
 
  for( i = 0; i <= n-2; i++ )
    printf("%d ",Array[i]);
  printf("%d\n",Array[n-1]);
  printf("%d\n",count);

  return 0;
}

