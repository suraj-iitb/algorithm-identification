#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,G[100][100];
int color[100],d[100],f[100],tt;

void DFS_visit(int v){
  int i;
  color[v]=GRAY;
  d[v]=++tt;
  for(i=0;i<n;i++){
    if(G[v][i]==0)continue;
    if(color[i]==WHITE){
      DFS_visit(i);
    }
  }
  color[v]=BLACK;
  f[v]=++tt;
}

void DFS(){
  int i;
  //初期化
  for(i=0;i<n;i++){
    color[i]=WHITE;
  }
  tt=0;
  for(i=0;i<n;i++){
    if(color[i]==WHITE){
      DFS_visit(i);
    }
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}
  



int main(){
  int i,j,u,k,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      G[u][v]=1;
    }
  }

  DFS();

  return 0;
}

      

