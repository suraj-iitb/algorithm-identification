#include <stdio.h>
#define N 100
#define INF 100000000

int G[N+1][N+1], vis[N+1], n, size[N+1];

void dfs(int p, int t){
  int i;
  vis[p] = t;
  for(i=1;i<=size[p];i++) if(t + 1 < vis[G[p][i]]) dfs(G[p][i], t + 1);
}

main(){
  int i, j, u;
  scanf("%d", &n);

  for(i=1;i<=n;i++){
    if(i<=n)break;
  }
  
  for(i=1;i<=n;i++){
    vis[i] = INF;
    scanf("%d", &u);
    scanf("%d", &size[u]);
    for(j=1;j<=size[u];j++) scanf("%d", &G[u][j]);
  }
  dfs(1, 0);
  for(i=1;i<=n;i++) printf("%d %d\n", i, (vis[i] == INF) ? -1 : vis[i]);
  return 0;
}

