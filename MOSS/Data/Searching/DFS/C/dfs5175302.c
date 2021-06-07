#include <stdio.h>
#define MAX 100
#define TRUE 1
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, time;
int m[MAX][MAX]={};
int color[MAX], d[MAX], f[MAX];

void dfs_init(int);
void dfs(void);
void dfs_visit(int);

int main()
{
  int i, j, k, u, v;

  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d%d", &u, &k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d", &v);
      v--;
      m[u][v]=TRUE;
    }
  }

  dfs();

  return 0;
}

void dfs_init(int u)
{
  for(u = 0; u < n; u++){
    color[u]=WHITE;
  }
  time=0;
}

void dfs(void)
{
  int u;
  dfs_init(u);
  for(u = 0; u < n; u++){
    if(color[u]==WHITE) dfs_visit(u);
  }
  for(u = 0; u < n; u++){
    printf("%d %d %d\n", u+1, d[u], f[u]);
  }
}

void dfs_visit(int u)
{
  color[u]=GRAY;
  d[u]=++time;
  for(int v = 0; v < n; v++){
    if(m[u][v]==WHITE) continue;
    if(color[v]==WHITE) dfs_visit(v);
  }
  color[u]=BLACK;
  f[u]=++time;
}

