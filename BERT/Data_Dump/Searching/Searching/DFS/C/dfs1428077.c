#include<stdio.h>
#define N 100
#define W 0
#define G 1
#define B 2

int n,A[N][N];
int d[N],f[N],color[N],t;

void dfs(int u){
  int v;
  color[u]=G;
  d[u]=++t;
  for(v=0;v<n;v++){
    if(A[u][v]==0) continue;
    if(color[v]==W){
      dfs(v);
    }
  }
  color[u]=B;
  f[u]=++t;
}

void dfs1(){
  int u;
  for(u=0;u<n;u++) color[u]=W;
  t=0;

  for(u=0;u<n;u++){
    if(color[u]==W){
      dfs(u);
    }
  }
  for(u=0;u<n;u++){
    printf("%d %d %d",u+1,d[u],f[u]);
    printf("\n");
  }
 
}    

main(){
  
  int i,j,k,u,v;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      A[u][v]=1;
    }
  }
 
  dfs1();
  return 0;
}
