#include <stdio.h>
int t=1;
int g[105][105],d[105],f[105];

void DFS(int i){
  int j;
  if(d[i]==0){
    d[i]=t;
    t++;
    for(j=1;g[i][j]!=-1;j++) if(d[g[i][j]]==0) DFS(g[i][j]);
    f[i]=t;
    t++;
  }
}

int main(){
  int n,i,j,u,k;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    for(j=1;j<=k;j++) scanf("%d",&g[i][j]);
    g[i][j]=-1;
  }
  for(i=1;i<=n;i++) DFS(i);
  for(i=1;i<=n;i++) printf("%d %d %d\n",i,d[i],f[i]);
  return 0;
}

