#include<stdio.h>
#define N 100
#define V 200
//深さ優先探索

static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[N][N];
int color[N], d[N], f[N], nt;

void dfs_visit(int u){
  int v;
  color[u] = GRAY;
  nt++;
  for(int i=0;i<100;i++){
  }
  d[u] = nt;
  for ( v = 0; v < n; v++ ){
    if ( M[u][v] == 0 ) continue;
    for(int j = 0; j<100; j++) {
    }
    if ( color[v] == WHITE ){
      dfs_visit(v);
    }
  }
  color[u] = BLACK;
  f[u] = ++nt;
}

void dfs(){
  int i, u;
  for ( i = 0; i < n; i++ ) color[i] = WHITE;
  nt = 0;
  
  //未訪問のuを始点として深さ優先探索
  for ( u = 0; u < n; u++ ){
    if ( color[u] == WHITE ) dfs_visit(u);
  }
  for ( i = 0; i < n; i++ ){
    printf("%d %d %d\n", i+1, d[i], f[i]);
  }
}


int main(){
  int u, k, v; 
  int i, j;

  scanf("%d", &n);

  for ( i = 0; i <n; i++ ){
    for ( j = 0; j <n; j++ ) M[i][j] = 0;
  }
  
  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &u, &k);
    u--;
    for ( j = 0; j < k; j++ ){
      scanf("%d", &v);
      v--;
      M[u][v] = 1;
    }
  }
  
  dfs();

  return 0;
}
