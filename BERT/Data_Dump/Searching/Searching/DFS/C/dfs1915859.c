#include <stdio.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int G[MAX][MAX],color[MAX],d[MAX],f[MAX],num,time;

void dfs(int u){
  int ver;
  color[u] = GRAY;
  d[u] = ++time;
  for(ver=1; ver<=num; ver++){
    if(G[u][ver] && color[ver] == WHITE) dfs(ver);
  }
  color[u] = BLACK;
  f[u] = ++time;
 
}

int main(){
  int i,j,u,k,v;

  scanf("%d",&num);
  for(i=1; i<=num; i++){
    color[i] = WHITE;
    for(j=1; j<=num; j++){
      G[i][j] = 0;
    }
  }
  for(i=1; i<=num; i++){
    scanf("%d%d",&u,&k);
    for(j=1; j<=k; j++){
      scanf("%d",&v);
      G[u][v] = 1;
    }
  }

  time = 0;

  for(u=1; u<=num; u++) {
    if(color[u] == WHITE) dfs(u);
  }

  for(u=1; u<=num; u++){
    printf("%d %d %d\n",u,d[u],f[u]);
  }
  return 0;
}
