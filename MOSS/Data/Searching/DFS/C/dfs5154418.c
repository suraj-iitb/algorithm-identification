#include <stdio.h>

void dfs(void);
void visit(int);

int n, G[101][101] ={0}, color[101], time, d[101], f[101];

int main()
{
  int i, j, u, k, a;

  scanf("%d",&n);
  for(i = 0; i < n; i++)
    {
      scanf("%d",&u);
      scanf("%d",&k);
      for(j = 0; j < k; j++)
	{
	  scanf("%d",&a);
	  G[u][a] = 1;
	}
    }
  dfs();
  return 0;
}

void dfs(void)
{
  int i;

  for(i = 1; i <= n; i++)
    {
      color[i] = 0;
    }
  time = 0;
  for(i = 1; i <= n; i++)
    {
      if(color[i] == 0)visit(i);
    }
  for(i = 1; i <= n; i++)
    {
      printf("%d %d %d\n",i, d[i], f[i]);
    }
}

void visit(int u)
{
  int i;

  color[u] = 1;
  d[u] = ++time;
  for(i = 1; i <= n; i++)
    {
      if(G[u][i] == 1 && color[i] == 0) visit(i);
    }
  color[u] = 2;
  f[u] = ++time;
}

