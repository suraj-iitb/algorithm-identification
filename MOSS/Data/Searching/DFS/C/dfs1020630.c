#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
int m[110],n,Adj[110][220],color[110],time,d[10000],f[10000];

void DFS_Visit(int u){
  int v,i;
  color[u] = GRAY; 
  d[u] = ++time;
  for(i = 1; i <= m[u]; i++){
    v = Adj[u][i];
    if(color[v] == WHITE){
      DFS_Visit(v);
    }
  }
  color[u] = BLACK; 
  f[u] = ++time;
}
void DFS(){
  int u;
  for(u = 1; u <= n; u++){
    color[u] = WHITE;
  }
  time = 0;
  for(u = 1; u <= n; u++){
    if(color[u] == WHITE){ 
      DFS_Visit(u); 
    }
  }
}


int main(){ 
  int u,i,j,dust;
  scanf("%d",&n);
  for(u = 1; u <= n; u++){
    for(j = 1; j <= n; j++){
      Adj[u][j]=0;
    }
  }
  for(u = 1; u <= n; u++){
    scanf("%d%d",&dust,&m[u]);
      for(i = 1; i <= m[u]; i++){
	scanf("%d",&Adj[u][i]);
      }	
  }
  
  DFS();
  for(u = 1; u <= n; u++){
    printf("%d %d %d\n",u,d[u],f[u]);
  }
  return 0;
}
