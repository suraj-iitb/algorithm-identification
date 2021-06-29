#include <stdio.h>
#include <stdlib.h>

int G[101][101];
int d[101];
int f[101];
int finded[101];  // init 0
/* 0:未訪問  1:訪問済 */

void dfs(int);
void visit(int, int);

main(){
  int i, j, k, l, n, adj;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d%d", &l, &k);
    for(j=0; j<k; j++){
      scanf("%d", &adj);
      G[l][adj] = 1;
    }
  }

  dfs(n);

  for(i=1; i<=n; i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }

  return 0;
}

void dfs(int n){
  int i;
  for(i=1; i<=n; i++){
    if(finded[i] == 0) visit(n, i);
  }
}

void visit(int n, int p){
  static int time=0;
  int j;

  finded[p] = 1;
  d[p] = ++time;

  for(j=1; j<=n; j++){
    if(G[p][j]==1 && finded[j]==0)
      visit(n, j);
  }
  f[p] = ++time;
}
