#include<stdio.h>
#define N 100
int G[N][N],d[N],f[N],color[N];
int n,time;

void visit(int u){
  int i;
  color[u]=1;
  d[u]=++time;
  for(i=0;i<n;i++){
    if(G[u][i]!=0){
    if(color[i]==0)
      visit(i);
    }
  }
  color[u]=2;
  f[u]=++time;
  
}

void dfs(){
  int i;
  for(i=0;i<n;i++)
    color[i]=0;
  time=0;
  for(i=0;i<n;i++)
    if(color[i]==0)
      visit(i);
  for(i=0;i<n;i++)
  printf("%d %d %d\n",i+1,d[i],f[i]);    
}

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      G[i][j]=0;

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      G[u-1][v-1]=1;
    }
  }
  dfs();

  
  return 0;
}
