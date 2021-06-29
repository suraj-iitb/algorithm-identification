#include <stdio.h>
#define N 100

int G[101][101],v[101],size[101];

void dfs(int p,int t){
  
  int i;
  
  v[p] = t;
  for(i = 1;i <= size[p];i++) if(t+1 < v[G[p][i]]) dfs(G[p][i],t+1);
  
}

int main(){
  
  int i,j,n,u;
  
  scanf("%d", &n);
  
  for(i = 1;i <= n;i++){
    v[i] = N;
    scanf("%d",&u);
    scanf("%d",&size[u]);
    for(j = 1;j <= size[u];j++) scanf("%d",&G[u][j]);
  }
  
  dfs(1, 0);
  
  for(i = 1;i <= n;i++) printf("%d %d\n",i,(v[i] == N) ? -1 : v[i]);
  
  return 0;
  
}

