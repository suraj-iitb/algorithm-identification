#include<stdio.h>

int main()
{
  int N, i, j, v, k, array[100];

  scanf("%d", &N);

  for( i=0; i<N; i++ ) scanf("%d", &array[i]);

  

  for( i=1; i<N; i++ )
    {
      v = array[i];
      j = i - 1;

      for( k=0; k<N; k++ )
	{
	  printf("%d", array[k]);
	  if( k == N-1 )break;
	  printf(" ");
	}
	  
      printf("\n");
       
      while( j>=0 && array[j]>v )
	{
	  array[j+1] = array[j];
	  j--;
	  array[j+1] = v;
	}    
    }

  for( i=0; i<N; i++ )
    {
      printf("%d", array[i]);
      if( i == N-1 )break;
      printf(" ");
    }
  
  printf("\n");

  return 0;
}



  

  


  

