#include <stdio.h>

#define MAX 100

typedef struct{
  int src,dst;
} Node;

void DFS(int,int,int[MAX][MAX]);

int t;
int visited[MAX];
Node node[MAX];

int main(){
  int n;
  int u,k,v;
  int i,j;
  int G[MAX][MAX];
  for(i = 0 ; i < MAX ; i++){
    for(j = 0 ; j < MAX ; j++){
      G[i][j] = 0;
    }
  }
  
  t=0;
  scanf("%d",&n);
  
  for(i = 0 ; i < n ; i++){
    scanf("%d%d",&u,&k);
    u=u-1;
    for(j = 0 ; j < k ; j++){
      scanf("%d",&v);
      v=v-1;
      G[u][v] = 1;
    }
    visited[i] = 0;
  }
  for(i = 0 ; i < n ; i++){
    if(!visited[i]){
      visited[i] = 1;
      DFS(i,n,G);
    }
  }
  for(i = 0 ; i < n ; i++){
    printf("%d %d %d",i+1,node[i].src,node[i].dst);
    printf("\n");
  }
  return 0;
}

void DFS(int v,int n,int G[MAX][MAX]){
  int i;
  node[v].src = ++t;
  for(i = 0 ; i < n ; i++){
    if(G[v][i] == 0){ continue; }
    if(visited[i] == 1){ continue; }
    visited[i] = 1;
    DFS(i,n,G);
  }
  node[v].dst = ++t;
}

