#include<stdio.h>

#define u 101
#define WHITE 0
#define BLACK 1
#define GRAY 2

int d[u],f[u],G[u][u],Adj[u][u],edg_number[u],color[u];
int length,time;

void DFS_Visit(int r){
  int i,v;

  color[r]=GRAY;
  d[r]=++time;

  for(i=1;i<=edg_number[r];i++){
    v=Adj[r][i];
    if(color[v]==WHITE){
      DFS_Visit(v);
    }
  }

    color[r]=BLACK;
    f[r]=++time;
}
  
void DFS(){
  int i;

  for(i=1;i<=length;i++){
    color[i] = WHITE;
    time = 0;
  }

  for(i=1;i<=length;i++){
    if(color[i] == WHITE){
      DFS_Visit(i);
    }

    printf("%d %d %d\n",i,d[i],f[i]);
  }
}

int main(){
  int i,j,iranai,u_number;

  scanf("%d",&length);

  for(i=1;i<=length;i++){
    scanf("%d",&iranai);
    scanf("%d",&edg_number[i]);
    for(j=1;j<=edg_number[i];j++){
      scanf("%d",&u_number);
      Adj[i][j]=u_number;
      G[i][u_number]=1;
    }
  }

  DFS();

  return 0;
}
