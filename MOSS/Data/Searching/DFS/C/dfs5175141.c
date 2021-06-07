#include<stdio.h>
#define N 101
#define WHITE 0
#define BLACK 2
#define GRAY 1

void dfs();
void dfs_visit();
int n, tt, M[N][N] = {}, d[N], f[N], color[N];

int main(){
  int i, j, v, u, k;
  scanf("%d", &n);
   
  for(i = 0; i < n; i++){
    scanf("%d%d", &u, &k);
    /*u--;*/
    for(j = 0; j < k; j++){
      scanf("%d", &v);
      /*v--;*/
      M[u][v] = 1;
    }
  }
  dfs();
  return 0;
}

void dfs(){
  int u;

  for(u = 1; u <= n; u++)color[u] = WHITE;
    tt = 0;

  for(u = 1; u <= n; u++){
    if(color[u] == WHITE) dfs_visit(u);
  }

  for(u = 1; u <= n; u++){
    printf("%d %d %d\n", u , d[u], f[u]);
  }
}

  
void  dfs_visit(int u){
  int v;
  color[u] = GRAY;
  d[u] = ++tt;
  for( v = 1; v <= n; v++){
    if(M[u][v] == 0) continue;
    if(color[v] == WHITE){
      dfs_visit(v);
    }
  }
  color[u] = BLACK;
  f[u] = ++tt;
}


