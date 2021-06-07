#include<stdio.h>


int G[100][100];
int f[100];
int time,n;
int d[100];
int c[100];


void visit(int u){
  int v;
  c[u] = 1;
  d[u] = ++time;
  for(v=0;v<n;v++){
    if(!G[u][v])continue;
    if(!c[v])visit(v);
  }
  c[u] = 2;
  f[u] = ++time;
}


void dfs(){
  int u;
  for(u=0;u<n;u++){
    c[u] = 0;
  }
  time = 0;
  for(u=0;u<n;u++){
    if(!c[u])visit(u);
  }
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}

int main(){
  int i,j,u,v,k;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&v);
    for(j=0;j<v;j++){
      scanf("%d",&k);
      G[u-1][k-1] = 1;
    }
  }

  dfs();
  return 0;
}
