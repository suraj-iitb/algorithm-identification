#include <stdio.h>
#define nMAX 100
#define T 100000000

int Graph[nMAX+1][nMAX+1], care[nMAX+1], size[nMAX+1];

void DFS(int p, int t)
{
  int i;
  care[p] = t;
  for(i=1; i<=size[p]; ++i)
    if(t+1 < care[Graph[p][i]])
      DFS(Graph[p][i], t+1);
}

int main(){
    int x, n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
    {
        care[i] = T;
        scanf("%d", &x);
        scanf("%d", &size[x]);
        for(int j = 1; j <= size[x]; ++j) scanf("%d", &Graph[x][j]);
    }

    DFS(1, 0);

    for (int i = 1; i <= n; ++i) printf("%d %d\n", i, (care[i] == T) ? -1 : care[i]);

    return 0;
}

