#include<stdio.h>

int n, G[100][100];
int color[100], d[100], f[100], tt;

void dfs_visit(int u){
  int v;
  color[u] = 1;
  d[u] = ++tt;
  for(v = 0;v < n;v++){
    if(G[u][v] != 0){
      if(color[v] == 0){
        dfs_visit(v);
      }
    }
  }
  color[u] = 2;
  f[u] = ++tt;
} 

void dfs(){
  int u;
  for(u = 0;u < n;u++) color[u] = 0;
  tt = 0;

  for(u = 0;u < n;u++){
    if(color[u] == 0) dfs_visit(u);
  }
  for(u = 0;u < n;u++){
    printf("%d %d %d\n", u + 1, d[u], f[u]);
  }
}


int main(){
  int u, k, v, i, j;

  scanf("%d", &n);

  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++){
      G[i][j] = 0;
    }
  }

  for(i = 0;i < n;i++){
    scanf("%d%d", &u, &k);
    for(j = 0;j < k;j++){
      scanf("%d", &v);
      G[u-1][v-1] = 1;
    }
  }

  dfs();

  return 0;
}
