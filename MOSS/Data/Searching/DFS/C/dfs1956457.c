#include <stdio.h>
 
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct{
  int u;
  int k;
  int v[N];
}Graph;

int n, time, top, u;
int color[N], G[N][N];
Graph F[N];
int d[N], f[N];

void dfs(void);
void visit(int);
int push(int);
int pop(void);
int isEmpty(void);
int isFull(void);

int main()
{

  int i, j;

  scanf("%d", &n);

  for(i=1; i<=n; i++){
    for(j=1; j<=n; j++){
      G[i][j] = 0;
    }
  }

  for(i=1; i<=n; i++){
    scanf("%d%d", &F[i].u, &F[i].k);
    for(j=1; j<=F[i].k; j++){
      scanf("%d", &F[i].v[j]);
      G[F[i].u][F[i].v[j]] = 1;
    }    
  }

  dfs();

  for(i=1; i<=n; i++){
    printf("%d %d %d\n", F[i].u, d[i], f[i]);
  }

  return 0;
}

void dfs(void){

  int u;

  for(u=1; u<=n; u++){
    color[u] = WHITE;
  }

  time = 0;

  for(u=1; u<=n; u++){
    if(color[u] == WHITE){
      visit(u);
    }
  }
}

void visit(int u){

  int v;

  color[u] = GRAY;
  d[u] = ++time;

  for(v=1; v<=n; v++){
    if(G[u][v] == 1){
      if(color[v] == WHITE){
	visit(v);
      }
    }
  }

  color[u] = BLACK;
  f[u] = ++time;

}
