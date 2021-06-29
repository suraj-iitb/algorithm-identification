#include <stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int G[100][100],n,color[100],d[100],f[100],time;


void dfs_visit(int u){
  int v;
  color[u] = GRAY;
  d[u] = ++time;
  for(v=0;v<n;v++){
    if(G[u][v]==0) continue;
    if(color[v] == WHITE){
      dfs_visit(v);
    }
  }
  color[u] = BLACK;
  f[u] = ++time;
}


void dfs(){
  int u;
  for(u=0;u<n;u++) color[u] = WHITE;
  time = 0;

  for(u=0;u<n;u++) {
    if(color[u] == WHITE) dfs_visit(u);
  }
  for(u=0;u<n;u++) {
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}
  

int main(){
  int i,j,u,k,v;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      G[u][v] = 1;
    }
  }

  dfs();

  return 0;
}

