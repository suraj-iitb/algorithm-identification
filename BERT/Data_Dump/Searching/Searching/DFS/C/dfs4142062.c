#include <stdio.h>

int size[101],G[101][101],d[101],f[101],t;

void dfs(int p){
  
  int i;
  
  d[p] = t++;
  for(i = 1;i <= size[p];i++) if(!d[G[p][i]]) dfs(G[p][i]);
  f[p] = t++;
  
}

int main(){
  
  int i,j,n,u,v;
  
  scanf("%d", &n);
  
  t = 1;
  for(i=1;i<=n;i++){
    d[i] = f[i] = 0;
    scanf("%d",&u);
    scanf("%d",&size[u]);
    for(j = 1;j <= size[u];j++) scanf("%d",&G[u][j]);
  }
  for(i = 1;i <= n;i++) if(!d[i]) dfs(i);
  for(i = 1;i <= n;i++) printf("%d %d %d\n", i, d[i], f[i]);
  
  return 0;
  
}
