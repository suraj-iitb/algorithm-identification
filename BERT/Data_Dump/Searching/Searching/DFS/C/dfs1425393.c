#include <stdio.h>

#define MAX_N 100

typedef struct{
  int src,dst;
} Node;

void dfs(int,int,int[MAX_N][MAX_N]);

int time,visited[MAX_N];
Node node[MAX_N];

int main(){
  int n,u,k,v,i,j;
  int G[MAX_N][MAX_N];
  for(i = 0 ; i < MAX_N ; i++){
    for(j = 0 ; j < MAX_N ; j++){
      G[i][j] = 0;
    }
  }
  time = 0;
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d%d",&u,&k); u--;
    for(j = 0 ; j < k ; j++){
      scanf("%d",&v); v--;
      G[u][v] = 1;
    }
    visited[i] = 0;
  }
  for(i = 0 ; i < n ; i++){
    if(!visited[i]){
      visited[i] = 1;
      dfs(i,n,G);
    }
  }
  for(i = 0 ; i < n ; i++){
    printf("%d %d %d\n",i+1,node[i].src,node[i].dst);
  }
  return 0;
}

void dfs(int v,int n,int G[MAX_N][MAX_N]){
  int i;
  node[v].src = ++time;
  for(i = 0 ; i < n ; i++){
    if(G[v][i] == 0){ continue; }
    if(visited[i] == 1){ continue; }
    visited[i] = 1;
    dfs(i,n,G);
  }
  node[v].dst = ++time;
}
