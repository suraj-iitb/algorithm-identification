#include<stdio.h>

#define MAX 105

int G[MAX][MAX],d[MAX],f[MAX],t=1;

void DFS(int i){
  int j;
  if(d[i]==0){
    d[i]=t;
    t++;
    for(j=1;G[i][j]!=-1;j++) if(d[G[i][j]]==0) DFS(G[i][j]);
    f[i]=t;
    t++;
  }
}

int main( ){
  int n,i,j,u,k;
  
  scanf("%d",&n);
  
  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    for(j=1;j<=k;j++) scanf("%d",&G[i][j]);
    G[i][j]=-1;
  }
  
  for(i=1;i<=n;i++) DFS(i);
  
  for(i=1;i<=n;i++) printf("%d %d %d\n",i,d[i],f[i]);
  
  return 0;
}



