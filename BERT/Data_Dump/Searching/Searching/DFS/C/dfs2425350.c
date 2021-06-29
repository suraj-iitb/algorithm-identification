#include<stdio.h>
#define N 100

int i, j, n, d[N], f[N], color[N], time, G[N][N] = {};

void visit(int u){

  int v;
  
  color[u] = 1;
  d[u] = ++time;
  for(v = 0 ; v < n ; v++){
    if(G[u][v] != 0){
      if(color[v] == 0){
	visit(v);
      }
    }
  }
  color[u] = 2;
  f[u] = ++time;
}

void dfs(){
  
  for(i = 0 ; i < n ; i++){
    color[i] = 0;
  }
  time = 0;
  
  for(i = 0 ; i < n ; i++){
    if(color[i] == 0){
      visit(i);
    }
  }
}

int main(){

  int a, k, u;

  scanf("%d", &n);
  for(i = 0 ; i < n ; i++){
    scanf("%d%d", &u, &k);
    for(j = 0 ; j < k ; j++){
      scanf("%d", &a);
      G[u-1][a-1] = 1;
    }
  }

  dfs();
  
  for(i = 0 ; i < n ; i++){
    printf("%d %d %d\n", i+1, d[i], f[i]);
  }

  return 0;
}
