#include<stdio.h>

#define WHITE -1
#define GRAY -2
#define BLACK -3
#define MAX 100

int n, time, d[MAX+1], f[MAX+1], color[MAX+1], M[MAX+1][MAX+1];

void visit( int u )
{
  int v;

  color[u] = GRAY;
  d[u] = ++time;

  for( v=0; v<n; v++ )
    {
      if( M[u][v] == 0 ) continue;
      if( color[v] == WHITE )
	{
	  visit(v);
	}
    }
  color[u] = BLACK;
  f[u] = ++time;
}


void dfs()
{
  int u;

  for( u=0; u<n; u++ ) color[u] = WHITE;
  time = 0;

  for( u=0; u<n; u++ )
    {
      if( color[u] == WHITE ) visit(u);
    }
  for( u=0; u<n; u++ )
    {
      printf("%d %d %d\n", u+1, d[u], f[u]);
    }
}


int main()
{
  int i, j, u, v, k;

  scanf("%d", &n);

  for( i=0; i<n; i++ )
    {
      for( j=0; j<n; j++ )
	{
	  M[i][j] = 0;
	}
    }

  for( i=0; i<n; i++ )
    {
      scanf("%d%d", &u, &k);
      u--;
      for( j=0; j<k; j++ )
	{
	  scanf("%d", &v);
	  v--;
	  M[u][v] = 1;
	}
    }

  dfs();

  return 0;
}

