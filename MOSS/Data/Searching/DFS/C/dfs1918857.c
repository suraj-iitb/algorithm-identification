#include<stdio.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
  
void dfs();
void visit(int );
  
int n, G[MAX][MAX], d[MAX], f[MAX], color[MAX], time=0;
  
int main()
{
  int i, j, u, k, v;
  
  scanf("%d", &n);
  for(i=0; i<=n; i++)
    {
      for(j=0; j<=n; j++)
    {
      G[i][j] = 0;
    }
    }
  for(i=1; i<=n; i++)
    {
      scanf("%d %d", &u, &k);
      for(j=1; j<=k; j++)
    {
      scanf("%d", &v);
      G[u][v] = 1;
    }
      color[u] = WHITE;
    }
  
  dfs();
  
  for(i=1; i<=n; i++) printf("%d %d %d\n", i, d[i], f[i]);
  
  return 0;
}
  
void dfs()
{
  int i;
  
  for(i=1; i<=n; i++)
    {
      if(color[i] == WHITE) visit(i);
    }
}
  
void visit(int u)
{
  int i;
  
  color[u] = GRAY;
  d[u] = ++time;
  
  for(i=1; i<=n; i++)
    {
      if(G[u][i] == 1 && color[i] == WHITE)
    {
      visit(i);
    }
    }
  color[u] = BLACK;
  f[u] = ++time;
}
