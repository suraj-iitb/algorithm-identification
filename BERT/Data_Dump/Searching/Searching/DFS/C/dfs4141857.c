#include<stdio.h>
#define N 100
#define W 0
#define G 1
#define B 2

void visit(int);
void dfs(void);

int n, m[N][N], color[N], d[N], f[N], t;

int main(){
  int u, v, k, i, j;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      m[i][j] = 0;
    }
  }
  for(i=0; i<n; i++){
    scanf("%d%d", &u, &k);
    u--;
    for(j=0; j<k; j++){
      scanf("%d", &v);
      v--;
      m[u][v] = 1;
    }
  }
  dfs();

  return 0;
}

void dfs(){
  int u;
  for(u=0; u<n; u++)color[u] = W;
  t = 0;
  for(u=0; u<n; u++){
    if(color[u] == W)visit(u);
  }
  for(u=0; u<n; u++){
    printf("%d %d %d\n", u+1, d[u], f[u]);
  }
}

void visit(int u){
  int v;
  color[u] = G;
  d[u] = ++t;
  for(v=0; v<n; v++){
    if(m[u][v] == 0)continue;
    if(color[v] == W){
      visit(v);
    }
  }
  color[u] = B;
  f[u] = ++t;
}

