#include<stdio.h>
#include<stdlib.h>
#define N 100
int n,time;
int g[N][N],color[N],d[N],f[N];

void visit(int u){
  int i;
  color[u]=1;
  d[u]=++time;
  for(i=0;i<n;i++){
    if(g[u][i]==0) continue;
    if(color[i]==0) visit(i);
  }
  color[u] = 2;
  f[u]= ++time;
}

void dfs(){
  int i;
  for(i=0;i<n;i++) color[i]=0;
  time = 0;
  for(i=0;i<n;i++){
    if(color[i] == 0) visit(i);
  }
}

int main(){
  int i,j;
  int u,v,k;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      g[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      g[u-1][v-1]=1;
    }
  }
  dfs();
  for(i=0;i<n;i++) printf("%d %d %d\n",i+1,d[i],f[i]);
  return 0;
}
