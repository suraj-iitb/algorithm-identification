#include<stdio.h>
#include<stdlib.h>

void binarySearch( int, int*, int );

int C = 0;

int main()
{
  int i, j, n, q, *S, *T;


  scanf("%d", &n);
  S = malloc( n * sizeof(int));
  for( i=0; i<n; i++ ) scanf("%d", &S[i]);

  scanf("%d", &q);
  T = malloc( q * sizeof(int));
  for( i=0; i<q; i++ )
    {
      scanf("%d", &T[i]);

      binarySearch( n, S, T[i]);
    }

  printf("%d\n", C);
  
  return 0;
}


void binarySearch( int n, int *S, int key)
{
  int left, right, mid;
  left = 0;
  right = n;

  while( left < right )
    {
      mid = (left + right)/2;
      if( key == S[mid] )
	{
	  C++;
	  return;
	}
      if( key > S[mid] )
	left = mid + 1;
      else if( key < S[mid] )
	right = mid;
    }
}
  

  

  

