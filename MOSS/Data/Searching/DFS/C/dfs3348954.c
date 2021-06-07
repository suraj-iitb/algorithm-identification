#include<stdio.h>
#define N 100
#define SHIRO 0
#define GRAY 1
#define KURO 2

int n,x[N][N];
int color[N],d[N],f[N],t;

void DFSsearch(int );
void dfs();

int main(){
  int i,j,k,u,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++) x[i][j] = 0;
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      x[u][v]=1;
    }
  }
  dfs();

  return 0;
}

void DFSsearch(int u){
  int v;
  color[u] = GRAY;
  d[u]=++t;
  for(v=0;v<n;v++){
    if(x[u][v]==0) continue;
    if(color[v]==SHIRO ){
      DFSsearch(v);
    }
  }
  color[u]=KURO;
  f[u]=++t;
}

void dfs(){
  int u;
  for(u=0;u<n;u++){
    color[u]=SHIRO;
  }
  t=0;
  for(u=0;u<n;u++){
    if(color[u]==SHIRO) DFSsearch(u);
  }
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}


