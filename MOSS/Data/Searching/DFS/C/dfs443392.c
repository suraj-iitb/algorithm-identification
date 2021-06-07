#include <stdio.h>

void dfs(int p, int n, int G[][101], int *pT, int *d, int *f) {
  int i;
  d[p] = *pT;
  for(i = 1; i <= n; ++i) {
    if(!G[p][i]) continue;
    if(d[i] != -1) continue;
    ++(*pT);
    dfs(i,n,G,pT,d,f);
    ++(*pT);
  }
  f[p] = *pT + 1;
}

int main() {
  int n;
  int i,j,k;
  int G[101][101];
  int src, dst;
  int T, d[101], f[101];
  for(i = 0; i < 101; ++i)  {
    d[i] = -1;
    for(j = 0; j < 101; ++j) {
      if(i == 0) G[i][j] = 1;
      else G[i][j] = 0;
    }
  }

  scanf("%d", &n);
  for(i = 1; i <= n; ++i) {
    scanf("%d %d", &src, &k);
    while(k--) {
      scanf("%d", &dst);
      G[src][dst] = 1;
    }
  }

  T = 0;
  dfs(0,n,G,&T,d,f);
  for(i = 1; i <= n; ++i) {
    printf("%d %d %d\n", i, d[i], f[i]);
  }
  return 0;
}
