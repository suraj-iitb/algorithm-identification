#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs_vis(int);
void dfs(void);
void visit(int);

int M[N][N],n;
int color[N],cnt,d[N],f[N]; /*ttはタイムカウンター*/

int main()
{
  int u,k,v,i,j;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      M[i][j] = 0;
    }
  }

  for(i = 0; i < n; i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }
  }

  dfs();

  return 0;
}

void dfs(void){
  int u;

  for(u = 0; u < n; u++)color[u] = WHITE;
  cnt = 0;

  for(u = 0; u < n; u++){
    if(color[u] == WHITE)dfs_vis(u);
  }
  for(u = 0; u < n; u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}

void dfs_vis(int u){
  int v;
  
  color[u] = GRAY;
  d[u] = ++cnt;
  for(v = 0; v < n; v++){
    if(M[u][v] == 0)continue;
    if(color[v] == WHITE){
      dfs_vis(v);
    }
  }
  color[u] = BLACK;
  f[u] = ++cnt;
}

