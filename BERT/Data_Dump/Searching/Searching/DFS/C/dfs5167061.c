#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int A[N][N], n;
int color[N], d[N], f[N], tt;

void visit(int u){
  int v;
  color[u] = GRAY;
  tt++;
  d[u] = tt;
  for(v = 0; v < n; v++){
    if(A[u][v] == 0) continue;
    if(color[v] == WHITE) visit(v);
  }
  color[u] == BLACK;
  f[u] = ++tt;
}

void dfs(){
  int i, u;
  for(i = 0; i < n; i++) color[i] = WHITE;
  tt = 0;
  for(u = 0; u < n; u++){
    if(color[u] == WHITE) visit(u);
  }
  for(i = 0; i < n; i++) printf("%d %d %d\n", i+1, d[i], f[i]);
}

int main(){
  int u, k, v, i, j;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      A[i][j] = 0;
    }
  }
  for(i=0; i<n; i++){
    scanf("%d%d", &u, &k);
    u--;
    for(j=0; j<k; j++){
      scanf("%d", &v);
      v--;
      A[u][v] = 1;
    }
  }
  dfs();

  return 0;
}

