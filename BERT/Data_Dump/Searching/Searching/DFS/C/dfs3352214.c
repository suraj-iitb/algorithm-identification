#include<stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs(void);
void visit(int);

int n, time, M[100][100], color[100], d[100], f[100];

int main()
{
  int i, j, u, k, v;

  scanf("%d", &n);

  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  M[i][j] = 0;
	  d[i] = 0; f[i] = 0;
	}
    }

  for(i=0;i<n;i++)
    {
      scanf("%d%d", &u, &k); u--;
      for(j=0;j<k;j++)
	{
	  scanf("%d", &v); v--;
	  M[u][v] = 1;
	}
    }

  dfs();

  return 0;
}

void dfs(void)
{
  int i;
  for(i=0;i<n;i++)
    {
      color[i] = WHITE;
    }
  
  for(i=0;i<n;i++)
    {
      if(color[i] == WHITE)visit(i);
    }
  
  for(i=0;i<n;i++)
    {
      printf("%d %d %d\n", i+1, d[i], f[i]);
    }
}

void visit(int u)
{
  int v;
  
  color[u] = GRAY;
  d[u] = ++time;
  for(v=0;v<n;v++)
    {
      if(M[u][v]==1 && color[v] == WHITE)visit(v);
    }
  color[u] = BLACK;
  f[u] = ++time;
}

