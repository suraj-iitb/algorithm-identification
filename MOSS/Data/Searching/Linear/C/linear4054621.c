#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i, j, n, q, C, *S, *T;
  C = 0;
  
  scanf("%d", &n);
  S = malloc( n * sizeof(int));
  for( i=0; i<n; i++ ) scanf("%d", &S[i]); 

  scanf("%d", &q);
  T = malloc( q * sizeof(int));

  for( i=0; i<q; i++ )
    {
      scanf("%d", &T[i]);
      
      for( j=0; j<n; j++ )
	{
	  if( T[i] == S[j] )
	    {
	      C++;
	      break;
	    }
	}
    }
	  
  printf("%d\n", C);

  return 0;
}
  
  

