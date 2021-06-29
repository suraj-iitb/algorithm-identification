#include <stdio.h>
#define o 100
#define X 100000000

int G[o+1][o+1], care[o+1], size[o+1];

void dfs(int pi, int t)
{
  int i;
  care[pi] = t;
  for(i=1; i<=size[pi]; ++i)
    if(t+1 < care[G[pi][i]])
      dfs(G[pi][i], t+1);
}


int main(){
  int x,n;
  int i,j;
  scanf("%d", &n);

  for(i=1; i<=n; ++i)
    {
      care[i] = X;
      scanf("%d", &x);
      scanf("%d", &size[x]);
      for(j=1; j<=size[x]; ++j) scanf("%d", &G[x][j]);
    }

  dfs(1, 0);

  for(i=1; i<=n; ++i)
    printf("%d %d\n", i, (care[i] == X) ? -1 : care[i]);

  return 0;
}


