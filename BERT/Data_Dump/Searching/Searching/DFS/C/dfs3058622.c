#include<stdio.h>
#define N 501

static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n,t,data[N][N],C[N],d[N],f[N];

void dfs_1(int u)
{
  int a;

  C[u] = GRAY;
  t++;
  d[u] = t;

  for(a=0; a<n; a++){
    if(data[u][a] == 0){
      continue;
    }
    if(C[a] == WHITE){
      dfs_1(a);
    }
  }

  C[u] = BLACK;
  f[u] = ++t;
}

void dfs_2()
{
  int i,b;

  for(i=0; i<n; i++){
    C[i] = WHITE;
  }

  t = 0;

  for(b=0; b<n; b++){
    if(C[b] == WHITE){
      dfs_1(b);
    }
  }

  for(i=0; i<n; i++){
    printf("%d %d %d",i+1,d[i],f[i]);
    printf("\n");
  }
}

int main()
{
  int i,j,u,k,v;

  scanf("%d",&n);

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      data[i][j] = 0;
    }
  }

  for(i=0; i<n; i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0; j<k; j++){
      scanf("%d",&v);
      v--;
      data[u][v] = 1;
    }
  }

  dfs_2();

  return 0;
}
