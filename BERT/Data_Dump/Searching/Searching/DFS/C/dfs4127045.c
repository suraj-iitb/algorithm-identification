#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,G[N][N];
int color[N],d[N],f[N],t;

void _dfs(int u){
  int v;
  color[u] = GRAY;
  d[u] = ++t;
  for(v=0;v<n;v++){
    if(G[u][v] == 0)continue;
    if(color[v] == WHITE){
      _dfs(v);
    }
  }
  color[u] = BLACK;
  f[u] = ++t;
}

void dfs(){
  int u;
  for(u=0;u<n;u++){
    color[u] = WHITE;
    t = 0;
  }

  for(u=0;u<n;u++){
    if(color[u] == WHITE)_dfs(u);
  }
  
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
      }
}

int main(){
  int u,v,k,i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)G[i][j]=0;
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

