#include <stdio.h>
#include <stdlib.h>

#define N 105
#define WHITE 0
#define GLAY 1
#define BLACK 2

int array[N][N], n;
int color[N], in[N], out[N], count;

int visit( int i )
{
  int j;

  color[i] = GLAY;
  in[i] = ++count;

  for( j = 1; j <= n; j++ )
    {
      if( array[i][j] == WHITE ) continue;
      if( color[j] == WHITE )
	visit( j );
    }
  color[i] = BLACK;
  out[i] = ++count;
}

void DFS()
{
  int i;

  for( i = 1; i <= n; i++ )
    color[i] = WHITE;

  count = 0;

  for( i = 1; i <= n; i++ )
    {
      if( color[i] == WHITE )
	visit( i );
    }

  for( i = 1; i <= n; i++ )
    printf("%d %d %d\n",i, in[i], out[i]);
  
}


int main()
{
  int u, k, v;
  int i,j;

  scanf("%d",&n);
  if( n < 1 || n > N-5 ) exit(1);

  for( i = 0; i <= n; i++ )
    {
      for( j = 0; j <= n; j++ )
	array[i][j] = 0;
    }

  for( i = 1; i <= n; i++ )
    {
      scanf("%d %d",&u, &k);

      for( j = 1; j <= k; j++ )
	{
	  scanf("%d",&v);
	  array[u][v] = 1;
	}
    }

  DFS();

  return 0;
}
	  

