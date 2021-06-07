#include <stdio.h>
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void visit(int);

int n,G[MAX][MAX],color[MAX],d[MAX],f[MAX],time;

void dfs(void){
  int u;
  for(u=0;u<n;u++){
    color[u] = WHITE;
  }
  time = 0;

  for(u=0;u<n;u++){
    if(color[u]==WHITE){
      visit(u);
    }
  }

  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}

void visit(int u){
  int v;

  color[u] = GRAY;
  d[u] = ++time;
  for(v=0;v<n;v++){
    if(G[u][v]==WHITE){
      continue;
    }
    if(color[v]==WHITE){
      visit(v);
    }
  }
  color[u] = BLACK;
  f[u] = ++time;
}

int main(){
  int u,v,k,i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
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

