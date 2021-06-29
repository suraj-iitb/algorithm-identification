#include <stdio.h>
#define N 101

int n;
int G[N][N], H[N], f[N], d[N];
int t = 0;

void DFS(int a)
{
  int i;
  for(i = 1; i <= n; i++){
    if (G[a][i] == 1 && H[i] == 0) {
      t++;
      d[i] = t;
      H[i] = 1;
      DFS(i);
    }
  }
  t++;
  f[a] = t;
}

int main()
{
  int i, j, u, k, v;

  scanf("%d",&n);
  for(i = 0; i < n; i++) {
    scanf("%d %d", &u, &k);
    for(j = 0; j < k; j++) {
      scanf("%d",&v);
      G[u][v] = 1;
    }
  }

  for(i = 1; i <= n; i++) {
    if (H[i] == 0){
      t++;
      d[i] = t;
      H[i] = 1;
      DFS(i);
    }
  }

  for(i = 1; i <= n; i++)
     printf("%d %d %d\n", i, d[i], f[i]);

  return 0;
}
