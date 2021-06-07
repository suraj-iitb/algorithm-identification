#include<stdio.h>
#define N 101
void dfs(void);
void visit(int);

int n,d[N],f[N],color[N],G[N][N]={},time;

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      G[u-1][v-1]=1;
    }
  }

  dfs();

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  return 0;
}
void dfs(){
  int v;
  for(v=0;v<n;v++){
    color[v]=0;
  }
  time=0;
  for(v=0;v<n;v++){
    if(color[v]==0){
      visit(v);
    }
  }
}
void visit(int u){
  int v;

  color[u]=1;
  d[u]=++time;
  for(v=0;v<n;v++){
    if(G[u][v]!=0){
      if(color[v]==0){
	visit(v);
      }
    }
  }
  color[u]=2;
  f[u]=++time;
}
