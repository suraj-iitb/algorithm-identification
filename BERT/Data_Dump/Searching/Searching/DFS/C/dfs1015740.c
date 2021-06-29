#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 101

enum COLOR{WHITE,BLACK,GRAY}color[N];
int G[N][N],time,d[N],f[N],n,A[N][N],edg[N];


void DFS_visit(int u){
  int v,i;
  color[u]=GRAY;
  d[u]=++time;
  for(i=1;i<=edg[u];i++){
    v=A[u][i];
    if(color[v]==WHITE)
      DFS_visit(v);
  }
  color[u]=BLACK;
  f[u]= ++time;
}

void DES(){
  int i;
  for (i=1;i<=n;i++){
    color[i]=WHITE;
    time=0;
  }
  for(i=1;i<=n;i++){
    if(color[i]== WHITE)
      DFS_visit(i);
    printf("%d %d %d\n",i,d[i],f[i]);
  }
}

int main(){
  int i ,j,k,ver,fff;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&ver,&edg[i]);
    for(j=1;j<=edg[i];j++){
      scanf("%d",&fff);
      G[i][fff]=1;
      A[i][j]=fff;
    } 
  }
  DES();
  return 0;
}
