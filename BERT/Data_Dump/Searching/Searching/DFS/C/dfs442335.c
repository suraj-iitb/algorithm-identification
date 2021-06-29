#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int tm, d[101], f[101], n;
bool a[101][101];

void dfs(int p)
{
  d[p] = tm++;

  int i;
  for(i = 1; i <= n; ++i)
    if(d[i] == 0 && a[p][i])
      dfs(i);

  f[p] = tm++;
}

int main()
{
  int u, k, i, j;

  while(scanf("%d", &n)!=EOF){
    memset(a, false, sizeof(a));
    memset(d, 0, sizeof(d));
    memset(f, 0, sizeof(f));

    for(i = 0; i < n; ++i){
      scanf("%d %d", &u, &k);

      while(0 < k--){
	scanf("%d", &j);
	a[u][j] = true;
      }
    }
    for(i = 1; i <= n; ++i)
      a[0][i] = true;

    tm = 0;
    dfs(0);

    for(i = 1; i <= n; ++i)
      printf("%d %d %d\n", i, d[i], f[i]);
  }

  return 0;
}
