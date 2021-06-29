#include<stdio.h>
#define MAX 101
#define BLACK 2
#define GLAY 1
#define WHITE 0

int a[MAX][MAX],color[MAX],d[MAX],f[MAX],n,time;

void visit(int u){
  int v;
  color[u]=GLAY;
  d[u]=++time;
  for(v=1;v<=n;v++){
    if(a[u][v]==0)continue;
    if(color[v]==WHITE)visit(v);
  }
  color[u]=BLACK;
  f[u]=++time;
}

void dfs(){
  int u;
  for(u=1;u<=n;u++)color[u]=WHITE;
  time=0;
  for(u=1;u<=n;u++){
    if(color[u]==WHITE)visit(u);
  }
}
  
int main(){
    int i,j,u,k,v;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      a[i][j]=0;
    }}

  for(i=1;i<=n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      a[u][v]=1;
    }
  }

  dfs();


  for(u=1;u<=n;u++)printf("%d %d %d\n",u,d[u],f[u]);

  return 0;
}

