#include<stdio.h>
#include<stdlib.h>
int linerSearch(int *,int,int);

int S[10000];
int linerSearch( int *A,int n, int key)
{
  int i=0;
  A[n] = key;
  while( A[i] != key )
    {
      i++;
      if( i == n )
	return 0;
    }
  return 1;
}

int main()
{
  int i,q,c=0,n,key;
  scanf("%d",&n);
  if( n > 10000 )
    exit(1);
  for( i = 0;i < n; i++ )
    {
      scanf("%d",&S[i]);
      if( S[i] < 0 || S[i] > 1000000000 )
        exit(1);
	}
  
  scanf("%d",&q);
  if( q > 500 )
    exit(1);
    for( i = 0; i < q; i++)
      {
	scanf("%d",&key);
	if( key < 0 || key > 1000000000 )
	  exit(1);
	c += linerSearch(S,n,key); 
      }
    printf("%d\n",c);

    return 0;
}

