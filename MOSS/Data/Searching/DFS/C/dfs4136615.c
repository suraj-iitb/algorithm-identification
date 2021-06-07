#include<stdio.h>
#define N 101

int n,g[N][N],color[N],d[N],f[N],t=0;

void visit(int u){
  int i;

  color[u]=1;

  d[u]=++t;

  for(i=0;i<n;i++){
    if(g[u][i]==0)continue;
    if(color[i]==0)visit(i);
  }

  color[u]=2;
  f[u]=++t;
}

void dfs(){
  int i;

  for(i=0;i<n;i++) color[i]=0;

  for(i=0;i<n;i++){
    if(color[i]==0) visit(i);
  }

  for(i=0;i<n;i++) printf("%d %d %d\n",i+1,d[i],f[i]);
}

int main(){

  int i,j,v,a,node;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      g[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&a,&v);
    for(j=0;j<v;j++){
      scanf("%d",&node);
      g[i][node-1]=1;
    }
  }
  dfs();

  return 0;
}

