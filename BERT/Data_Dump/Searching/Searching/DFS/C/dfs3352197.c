#include <stdio.h>

#define white 0
#define glay 1
#define black 2

int adj[100][100],n;
int color[100],d[100],f[100],tt;

void dfs_visit(int u){
  int v;
  color[u]=glay;
  d[u]=++tt;
  for(v=0;v<n;v++){
    if(adj[u][v]==0)continue;
    if(color[v]==white)dfs_visit(v);
  }

color[u]=black;
f[u]=++tt;

}

void dfs(){
  int u;
  for(u=0; u<n; u++)color[u]=white;
  tt=0;

  for(u=0; u<n ;u++){
    if(color[u]==white)dfs_visit(u);
  }
  for(u=0;u<n;u++)printf("%d %d %d\n",u+1,d[u],f[u]);
  
}




int main(){int u,k,v,i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)adj[i][j]=0;
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      adj[u][v]=1;
    }
  }


  dfs();
  return 0;
}

