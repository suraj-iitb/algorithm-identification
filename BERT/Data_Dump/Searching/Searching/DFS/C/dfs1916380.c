#include<stdio.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

void visit(int);
void dfs(void);

int n,time,graph[MAX][MAX],d[MAX],f[MAX],color[MAX];

int main()
{
  int u,k,i,j,v;

  scanf("%d",&n);

  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      graph[i][j] = 0;
    }
  }


  for(i = 1; i <= n; i++){
    scanf("%d%d",&u,&k);
    for(j = 1; j <= k; j++){
      scanf("%d",&v);
      graph[u][v] = 1;
    }
  }
  dfs();

  for( u = 1; u <= n; u++){
    printf("%d %d %d\n",u,d[u],f[u]);
  }

  return 0;
}

void dfs()
{
  int u;

  for(u = 1; u <= n; u++){
    color[u] = WHITE;
  }
  time = 0;
  for(u = 1; u <= n; u++){
    if(color[u] == WHITE) visit(u);
  }
}

void visit(int u)
{
  int v;

  color[u] = GRAY;
  d[u] = ++time;

  for(v = 1; v <= n; v++){
    if(graph[u][v] == 0) continue;
    if(color[v] == WHITE) visit(v);
  }
  color[u] = BLACK;
  f[u] = ++time;
}
