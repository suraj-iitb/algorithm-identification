#include <stdio.h>

int G[100][100];
int d[100];
int f[100];
int c[100];
int time1,n;

void visit(int);
void dfs(void);

void visit(int u)
{
  int i;

  c[u] = 1;
  d[u] = ++time1;

  for(i=0;i<n;i++){
    if(!G[u][i]) continue;
    if(!c[i]) visit(i);
  }

  c[u] = 2;
  f[u] = ++time1;
}

void dfs()
{
  int i;

  for(i=0;i<n;i++){
    c[i] = 0;
  }

  time1 = 0;

  for(i=0;i<n;i++){
    if(!c[i]) visit(i);
  }

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}

int main()
{
  int i,j,u,v,k;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&v);
    for(j=0;j<v;j++){
      scanf("%d",&k);
      G[u-1][k-1] = 1;
    }
  }

  dfs();

  return 0;
}
