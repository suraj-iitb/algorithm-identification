#include<stdio.h>

#define MAX 110
#define WHITE 0
#define GRAY 1
#define BLACK 2
int n,time;
int dis[MAX],fin[MAX],color[MAX],num[MAX][MAX];
void DFS(void);
void Visit(int);

int main(){
  int i,j,k,u,v;
  
  scanf("%d",&n);
  
  for(i=1; i<=n; i++){
    scanf("%d%d",&u,&k);
    for(j=1; j<=k; j++){
      scanf("%d",&v);
      num[u][v] = 1;
    }
  }
  DFS();

  for(i=1; i<=n; i++){
    printf("%d %d %d\n",i,dis[i],fin[i]);
  }
  
  return 0;
}

void DFS(){
  int u;
  for(u=1; u<=n; u++){
    color[u] = WHITE;
  }
  time = 0;
  for(u=1; u<=n; u++){
    if(color[u] == WHITE) Visit(u);
  }
}

void Visit(int u){
  int v;
  color[u] = GRAY;
  dis[u] = ++time;
  for(v=1; v<=n; v++){
    if(num[u][v] == 1 && color[v] == WHITE) Visit(v);
  }
  color[u] = BLACK;
  fin[u] = ++time;
}

