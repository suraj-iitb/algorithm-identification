#include<stdio.h>
#define N 501
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
int n, M[N][N];
int color[N], p[N], y[N], tt;
void dfs_visit(int u){
  int v;
  color[u] = GRAY;
  tt++;
  p[u] = tt;
  for ( v = 0; v < n; v++ ){
    if ( M[u][v] == 0 ) continue;
    if ( color[v] == WHITE ){
      dfs_visit(v);
    }
  }
  color[u] = BLACK;
  y[u] = ++tt;
}
void dfs(){
  int i, k;
  for ( i = 0; i < n; i++ ) color[i] = WHITE;
  tt = 0;
  for ( k = 0; k < n; k++ ){
    if ( color[k] == WHITE ) dfs_visit(k);
  }
  for ( i = 0; i < n; i++ ){
    printf("%d %d %d\n", i+1, p[i], y[i]);
  }
}
int main(){
  int u, k, v; 
  int i, e;
  scanf("%d", &n);
  for ( i = 0; i <n; i++ ){
    for ( e = 0; e <n; e++ ) M[i][e] = 0;
  } 
  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &u, &k);
    u--;
    for ( e = 0; e < k; e++ ){
      scanf("%d", &v);
      v--;
      M[u][v] = 1;
    }
  }  
  dfs();
  return 0;
}

