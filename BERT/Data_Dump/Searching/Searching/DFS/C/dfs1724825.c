#include <stdio.h>
int n;
int adj[101][101];
int used[101];
int f[101];
int d[101];
int time=0;
void dfs(int x){
  int i;
  for(i=1;i<=n;i++){
    if(adj[x][i]==1 && used[i]==0){
      used[i]=1;time++;d[i]=time;
      dfs(i);
    }
  }
    time++;
    f[x]=time;
  
  
}
int main(){
  int i,j;
  int u,k;
  int ad;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&ad);
      adj[u][ad]=1;
    }
  }
  for(i=1;i<=n;i++){
    if(used[i]==0){
      time++;
      d[i]=time;
      used[i]=1;
      dfs(i);
    }
  }
  for(i=1;i<=n;i++)printf("%d %d %d\n",i,d[i],f[i]);
  return 0;
}
