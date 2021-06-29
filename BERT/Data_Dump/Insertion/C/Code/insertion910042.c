#include <stdio.h>
int main(){
  int i, j, k;
  int length;
  int key;
  int A[100];
  scanf("%d",&length);
  for( i=0; i <= length-1; i++ )
    {
      scanf("%d", &A[i]);
    }
  for( k = 0; k <= length-1; k++ )
    {
      printf("%d", A[k]);
      if( k != length-1 )
	{
	  printf(" ");
	}
    }
  printf("\n");
  for( i = 1; i <= length-1; i++ )
    {
      key = A[i];
      j = i - 1;
      while( j >= 0 && A[j] > key )
	{
	  A[j+1] = A[j];
	  j--;
	}
      A[j+1] = key;
      for( k = 0; k <= length-1; k++ )
	{
	  printf("%d", A[k]);
	  if( k != length-1 )
	    {
	      printf(" ");
	    }
	}   
      printf("\n");
    }
  return 0;
}
