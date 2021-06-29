#include <stdio.h>

int n,M[100][100],color[100],d[100],f[100],time;

void dfs_visit(int u){
  int v;
  color[u]=1;
  d[u]=++time;
  for(v=0;v<n;v++){
    if(M[u][v]==0){
      continue;
    }
    if(color[v]==0){
      dfs_visit(v);
    }
  }
  color[u]=2;
  f[u]=++time;
}
void dfs(){
  int u;
  for(u=0;u<n;u++){
    color[u]=0;
  }
  time=0;
  for(u=0;u<n;u++){
    if(color[u]==0){
      dfs_visit(u);
    }
  }
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}
int main(void)
{
  int i,j,k,u,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }
  dfs();

  return 0;
}
