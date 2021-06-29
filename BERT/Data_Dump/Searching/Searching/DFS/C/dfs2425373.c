#include <stdio.h>
#define N 101

int n, time, A[N][N], color[N], d[N], f[N];

void dfs();
void visit(int);

int main(){
  int i, j, u, k, v;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      A[i][j] = 0;
    }
  }

  for(i = 0; i < n; i++){
    scanf("%d%d",&u, &k);
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      A[u-1][v-1] = 1;
    }
  }

  dfs();
  
  return 0;
}

void dfs(){
  int u;
  for(u = 0; u < n; u++) color[u] = 0;
  time = 0;
  for(u = 0; u < n; u++){
    if(color[u] == 0) visit(u);
  }
  for(u = 0; u < n; u++) printf("%d %d %d\n", u+1, d[u], f[u]);
}

void visit(int u){
  int v;
  color[u] = 1;
  d[u] = ++time;
  for(v = 0; v < n; v++){
    if(A[u][v] == 1){
      if(color[v] == 0) visit(v);
    }
  }
  color[u] = 2;
  f[u] = ++time;
}
