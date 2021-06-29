#include<stdio.h>

#define N 100

int n, x[N][N];
int ch[N], d[N], f[N], num;

void depth(int u){
  int v;
  ch[u]=1;
  d[u]=++num;
  for(v=0 ; v<n ; v++){
    if(x[u][v]==0)continue;
    if(ch[v]==0)depth(v);
  }
  ch[u]=2;
  f[u]=++num;
}

void dfs(){
  int u;
  for(u=0 ; u<n ; u++)ch[u]=0;
  num=0;
  for(u=0 ; u<n ; u++)if(ch[u]==0)depth(u);
  for(u=0 ; u<n ; u++)printf("%d %d %d\n", u+1, d[u], f[u]);
}

int main(){
  int u, v, k, i, j;
  scanf("%d", &n);
  for(i=0 ; i<n ; i++){
    for(j=0 ; j<n ; j++){
      x[i][j]=0;
    }
  }
  for(i=0 ; i<n ; i++){
    scanf("%d%d", &u, &k);
    u--;
    for(j=0 ; j<k ; j++){
      scanf("%d", &v);
      v--;
      x[u][v]=1;
    }
  }
  dfs();
  return 0;
}

