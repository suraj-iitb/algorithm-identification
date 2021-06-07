#include <stdio.h>
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int V,time,color[N],G[N][N],d[N],f[N];
void DFS(void);
void DFS_Visit(int);

main(){
  int i,j,k,l;
  int Adj[N];
  scanf("%d",&V);
  for(i=1;i <= V;i++) {
    for(j=1;j <= V;j++){
      G[i][j] = WHITE;
    }
  }
  
  for(i=1;i <= V;i++){
    scanf("%d%d",&k,&l);
    for(j=1;j <= l;j++){
      scanf("%d",&Adj[j]);
      G[k][Adj[j]] = GRAY;
    }
  }
  
  DFS();
  for(i=1;i<=V;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}


void DFS(){
  int u;
  for(u=1;u <= V;u++){
    color[u] = WHITE;
    time = 0;
  }
  for(u=1;u <= V;u++){
    if(color[u] == WHITE){
      DFS_Visit(u);
    }
  }
}

void DFS_Visit(int u){
  int v;
  color[u] = GRAY; // White vertex u has just been discovered
  d[u] = ++time;
  for(v=1;v<= V ;v++){ // Explore edge (u,v)
    if(color[v] == WHITE && G[u][v] == GRAY){
      DFS_Visit(v);
    }
  }
  color[u] = BLACK; // Blacken u; it is finished
  f[u] = ++time;
  
}
