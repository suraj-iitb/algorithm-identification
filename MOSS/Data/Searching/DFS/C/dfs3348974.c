#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,m[100][100],color[100],d[100],f[100],tt;

void dfs_v(int u){
  int v;
  color[u]=GRAY;
  d[u]=++tt;
  for(v=0;v<n;v++){
    if(m[u][v]==0)continue;
    if(color[v]==WHITE){
      dfs_v(v);
    }
  }
  color[u]=BLACK;
  f[u]=++tt;
}

void dfs(){
  int u;
  for(u=0;u<n;u++){
    color[u]=WHITE;
  }
  tt=0;
  for(u=0;u<n;u++){
    if(color[u]==WHITE)dfs_v(u);
  }
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}

int main(){
  int u,v,k,i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      m[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      m[u][v]=1;
    }
  }
  dfs();
  return 0;
}

