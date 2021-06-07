#include<stdio.h>
int color[105],k[105],d[105],f[105],G[105][105];
int u,time,v;
void DFS_Visit(int u){
  int i;
  color[u]=2;
  d[u]=++time;
  for(i=0;i<k[u];i++)
    if(color[G[u][i]]==1)
      DFS_Visit(G[u][i]);
  color[u]=0;
  f[u]=++time;
}
void DFS(int n){
  int i;
  for(i=1;i<=n;i++){
    color[i]=1;
    time=0;
  }
  for(i=1;i<=n;i++){
    if(color[i]==1){
      DFS_Visit(i);
    }
  }
}
int main(void){
  int n,i,j,k1;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k1);
    k[u]=k1;
    for(j=0;j<k[u];j++){
      scanf("%d",&v);
      G[u][j]=v;
    }  
  } 

  DFS(n);
  for(i=1;i<=n;i++)
    printf("%d %d %d\n",i,d[i],f[i]);
  return 0;
}
