#include <stdio.h>

#define N 1000
#define Q 500

int S[N*10], T[Q];
int count = 0;

int Search( int, int );

int main()
{
  int n,q;
  int i;

  scanf("%d",&n);
  for( i = 0; i < n; i++ )
    scanf("%d",&S[i]);
  scanf("%d",&q);
  for( i = 0; i < q; i++ )
    scanf("%d",&T[i]);

  for( i = 0; i < q; i++ )
    {
      if( Search( n, T[i]) == 1 )
	count++;
    }

  printf("%d\n",count);

  return 0;
}

int Search( int n, int x )
{
  int i = 0;

  S[n] = x;

  while( S[i] != x )
    i++;
  if( i == n )
    return 0;
  return 1;
}

