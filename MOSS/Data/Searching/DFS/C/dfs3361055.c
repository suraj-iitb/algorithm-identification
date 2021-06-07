#include<stdio.h>

int G[110][110]={};
int d[110];
int f[110];

int cnt = 0;

void dfs(int i, int n)
{
  int j;

  d[i] = ++cnt;
  for(j = 1;j <= n;j++){
    if(G[i][j] != 1) continue;
    else G[i][j] = 0;
    
    if(d[j] == 0) dfs(j, n);
  }
  f[i] = ++cnt;
}

int main()
{
  int n;
  int i,j;
  int u,k,v;
  
  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d%d", &u, &k);

    for(j = 0;j < k;j++){
      scanf("%d", &v);
      G[u][v] = 1;
    }
  }

  for(i = 1;i <= n;i++)
    if(d[i] == 0) dfs(i, n);

  for(i = 1;i <= n;i++)
    printf("%d %d %d\n", i, d[i], f[i]);
  
  return 0;
}

