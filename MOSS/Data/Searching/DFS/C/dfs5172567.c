#include <stdio.h>
#define N 100

int G[N+1][N+1], size[N+1], d[N+1], f[N+1], n, t;

void dfs(int p){
  int i;
  d[p] = t++;
  for(i=1;i<=size[p];i++) if(!d[G[p][i]]) dfs(G[p][i]);
  f[p] = t++;
}

int main(){
  int i, j, u, v;
  scanf("%d", &n);
  t = 1;
  for(i=1;i<=n;i++){
    d[i] = f[i] = 0;
    scanf("%d", &u);
    scanf("%d", &size[u]);
    for(j=1;j<=size[u];j++) scanf("%d", &G[u][j]);
  }
  for(i=1;i<=n;i++) if(!d[i]) dfs(i);
  for(i=1;i<=n;i++) printf("%d %d %d\n", i, d[i], f[i]);
  return 0;
}
