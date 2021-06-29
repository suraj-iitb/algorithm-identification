#include <stdio.h>

#define N 100000
#define Q 50000

int S[N], T[Q];

int Search( int, int );

int main()
{
  int n,q;
  int i;
  int count = 0;
  
  scanf("%d",&n);
  for( i = 0; i < n; i++ )
    scanf("%d",&S[i]);
  scanf("%d",&q);
  for( i = 0; i < q; i++ )
    scanf("%d",&T[i]);

  for( i = 0; i < q; i++ )
    {
      if( Search( n, T[i] ) == 1 )
	count++;
    }

  printf("%d\n",count);

  return 0;
}

int Search( int n, int x )
{
  int right, left, mid;

  left = 0;
  right = n;

  while( left < right )
    {
      mid = ( left + right ) / 2;

      if( S[mid] == x )
	return 1;
      else if( x < S[mid] )
	right = mid;
      else
	left = mid+1;
    }
  return 0;
}

