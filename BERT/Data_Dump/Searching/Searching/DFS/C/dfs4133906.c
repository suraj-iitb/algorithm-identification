#include<stdio.h>

#define  N 100

int G[N][N];

int d[N],f[N],t =0,visited[N];

void visit(int i,int max){
  int j;
  visited[i] = 1;
  d[i] = ++t;
  for(j=0;j<max;j++){
    if(G[i][j] == 1 && visited[j]!=1){
      visit(j,max);
    }
  }

  f[i] = ++t;
}

int main () {
  int n,u,k,v,i,j;

  scanf("%d",&n);
  for(i=0;i<n;++i){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;++j){
      scanf("%d",&v);
      --v;
      G[u][v] = 1;
    }

  }
  for(i=0;i<n;++i){
    if(visited[i]!=1){
      visit(i,n);
    }
  }

  for(i=0;i<n;++i){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  return 0;
}
  

