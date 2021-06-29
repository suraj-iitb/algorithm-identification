#include <stdio.h>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs_visit(int);
void dfs(void);

int n,M[N][N],color[N],d[N],f[N],t=0;

int main()
{
  int u,k,v;
  int i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++) M[i][j] = 0;
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }
  }

  dfs();

  return 0;
}

void dfs()
{
  int x;

  for(x=0;x<n;x++) color[x] = WHITE;

  for(x=0;x<n;x++){
    if(color[x] == WHITE) dfs_visit(x);
  }

  for(x=0;x<n;x++) printf("%d %d %d\n",x+1,d[x],f[x]);
}

void dfs_visit(int x)
{
  int c;
  color[x] = GRAY;
  t++;
  d[x] += t;
  for(c=0;c<n;c++){
    if(M[x][c] == 0) continue;
    if(color[c] == WHITE) dfs_visit(c);
  }
  color[x] = BLACK;
  t++;
  f[x] += t;
}

