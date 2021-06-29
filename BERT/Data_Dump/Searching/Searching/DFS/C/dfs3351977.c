#include<stdio.h>
#define N 1000
#define WHITE 0
#define BLACK 2
#define GRAY 1
int n,M[N][N],color[N],d[N],f[N],tt;
void dfs();
void visit(int);
int main(){
  scanf("%d",&n);
  int i,j,u,v,k;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
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
void dfs(){
  int u;
  for(u=0;u<n;u++){
    color[u]=WHITE;
  }
  tt=0;
  for(u=0;u<n;u++){
    if(color[u]==WHITE) visit(u);
  }
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}
void visit(int u){
  int v;
  color[u]=GRAY;
  d[u]=++tt;
  for(v=0;v<n;v++){
    if(M[u][v]==0)continue;
    if(color[v]==WHITE){
      visit(v);
    }
  }
  color[u]=BLACK;
  f[u]=++tt;
}

