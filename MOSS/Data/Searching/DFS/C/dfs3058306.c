#include<stdio.h>
#define N 100

int n, G[N][N];
int c[N], d[N], f[N], t;

void visit(int u)
{
  int i;
  c[u] = 1;
  d[u] = ++t;
  for(i = 0; i < n; i++)
    {
      if(G[u][i] == 0)
	{
	  continue;
	}
      if(c[i] == 0)
	{
	  visit(i);
	}
    }
  c[u] = 2;
  f[u] = ++t;
}

void dfs()
{
  int i;
  for(i = 0; i < n; i++)
    {
      c[i] = 0;
    }
  t = 0;
  for(i = 0; i < n; i++)
    {
      if(c[i] == 0)
	{
	  visit(i);
	}
    }
  for(i = 0; i < n; i++)
    {
      printf("%d %d %d\n", i+1, d[i], f[i]);
    }
}

int main()
{
  int i, j, k, u, v;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
	{
	  G[i][j] = 0;
	}
    }

  for(i = 0; i < n; i++)
    {
      scanf("%d %d", &u, &k);
      u--;
      for(j = 0; j < k; j++)
	{
	  scanf("%d", &v);
	  v--;
	  G[u][v] = 1;
	}
    }
  dfs();
  return 0;
} 

