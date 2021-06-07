#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void DFS(void);
void DFS_visit(int);

int n, A[N][N], d[N], f[N], color[N], time;

int main()
{
  int i, j, u, k, v;

  scanf("%d",&n);

  for(i = 0; i < n; i++)
    {
      scanf("%d%d",&u,&k);
      u--;
      for(j = 0; j < k; j++)
	{
	  scanf("%d",&v);
	  v--;
	  A[u][v] = 1;
	}
    }

  DFS();

  return 0;
}

void DFS(void)
{
  int u;
  for(u = 0; u < n; u++)
    {
      color[u] = WHITE;
    }
  time = 0;

  for(u = 0; u < n; u++)
    {
      if(color[u] == WHITE)DFS_visit(u);
    }
  for(u = 0; u < n; u++)
    {
      printf("%d %d %d\n",u+1, d[u],f[u]);
    }
}

void DFS_visit(int u)
{
  int v;

  color[u] = GRAY;
  d[u] = ++time;

  for(v = 0; v < n; v++)
    {
      if(A[u][v] == 0)continue;
      if(color[v] == WHITE)DFS_visit(v);
    }
  color[u] = BLACK;
  f[u] = ++time;
}


