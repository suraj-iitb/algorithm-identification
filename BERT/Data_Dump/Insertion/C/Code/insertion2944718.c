#include <stdio.h>
#include <stdlib.h>
#define N 100
#define FAC 1000
int main()
{
  int i,j,k,v,card[N],n;
  scanf("%d",&n);
  if( n > N )
    exit(1);
  for( i = 0; i < n; i++ )
    {
      scanf("%d",&card[i]);
      if( card [i] > FAC || card[i] < 0 )
	exit(1);
    }
  for( i = 1; i <= n; i++ )
    {
      for( k = 0; k < n; k++ )
	{
	  if( k == n-1 )printf("%d",card[k]);
	  else printf("%d ",card[k]);
	}
      printf("\n");
      v = card[i];
      j = i-1;
      while ( j >= 0 && card[j] > v )
	{
	  card[j+1] = card[j];
	  j--;
	  card[j+1] = v;
	}
    }
  return 0;
}

