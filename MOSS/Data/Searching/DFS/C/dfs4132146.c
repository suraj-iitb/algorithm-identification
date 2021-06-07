#include <stdio.h>

#define W 0
#define G 1
#define B 2

int n, m[100][100], c[100], t, d[100], f[100];

void dfs(int u)
{
  int i;
  
  c[u] = G;
  d[u] = ++t;
  for (i = 0; i < n; i++){
    if (m[u][i] == 0)
      continue;
    if (c[i] == W)
      dfs(i);
  }
  c[u] = B;
  f[u] = ++t;
}

int main()
{
  int i, j, k, u, v;
  
  scanf("%d",&n);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      m[i][j] = 0;
  for (i = 0; i < n; i++){
    scanf("%d%d",&u,&k);
    for (j = 0; j < k; j++){
      scanf("%d",&v);
      m[u-1][v-1] = 1;
    }
  }
  for (i = 0; i < n; i++)
    c[i] = W;
  t = 0;
  for (i = 0; i < n; i++)
    if (c[i] == W)
      dfs(i);
  for (i = 0; i < n; i++)
    printf("%d %d %d\n",i+1,d[i],f[i]);
    
  return 0;
}

