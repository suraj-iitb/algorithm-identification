#include <stdio.h>
#define N 101

void dfs(int);
void visit(int, int);

int time, d[N], f[N], color[N], list[N][N];

int main(){
  int n, i, j, k, u, v;

  scanf("%d", &n);

  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      list[i][j] = 0;
    }
  }

  for(i = 1; i <= n; i++){
    scanf("%d%d", &u, &k);
    for(k; k > 0; k--){
      scanf("%d", &v);
      list[u][v] = 1;
    }
  }

  dfs(n);

  for(i = 1; i <= n; i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }
  
  return 0;
}

void dfs(int n){
  int i;
  for(i = 1; i <= n; i++) color[i] = 0;
  for(i = 1; i <= n; i++){
    if(color[i] == 0) visit(i, n);
  }
}

void visit(int r, int n){
  int i;

  color[r] = 1;
  d[r] = ++time;
  for(i = 1; i <= n; i++){
    if(list[r][i] == 1 && color[i] == 0)
      visit(i, n);
  }
  color[r] = 2;
  f[r] = ++time;
}
