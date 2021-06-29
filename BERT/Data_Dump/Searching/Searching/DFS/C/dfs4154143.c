#include <stdio.h>

int graph[101][101],d[101],f[101],t=1;
void dfs(int);

int main(){
  int j,i,n,k,u,id;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
      scanf("%d%d",&u,&k);
      for(j=1;j<=k;j++) scanf("%d",&graph[i][j]);
      graph[i][j]=-1;
    }
  for(i=1;i<=n;i++) dfs(i);
  for(id=1;id<=n;id++) printf("%d %d %d\n",id,d[id],f[id]);
  return 0;
}

void dfs(int i){
  int j;
  if(d[i]==0){
      d[i]=t;
      t++;
      for(j=1;graph[i][j]!=-1;j++) if(d[graph[i][j]]==0) dfs(graph[i][j]);
      f[i]=t;
      t++;
    }
}
