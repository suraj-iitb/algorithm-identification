#include <stdio.h>

#define MAXN 101 /*添字0は使わないから1多い*/
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
  int color;
  int d;
  int f;
} NODE;


void scanData(int [][MAXN],int);
void dfs(int [][MAXN], NODE *, int);
int visit(int [][MAXN], NODE *,int, int, int);


int main()
{
  int i, j, n;
  int M[MAXN][MAXN];
  NODE Node[MAXN];

  scanf("%d",&n);
  scanData(M, n);

  dfs(M,Node,n);

  for(i = 1; i <= n; i++) {
    printf("%d %d %d\n", i, Node[i].d, Node[i].f);
  }  
  return 0;
}

void scanData(int M[][MAXN], int n)
{
  int i, j, u, k, v;

  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      M[i][j] = 0;
    }
  }

  for(i = 1; i <= n; i++) {
    scanf("%d%d",&u,&k);

    for(j = 1; j <= k; j++) {
      scanf("%d",&v);
      M[i][v] = 1;
    }
  }
}

void dfs(int M[][MAXN], NODE *Node, int n)
{
  int i, time = 0;
  
  for(i = 1; i <= n; i++) {
    Node[i].color = WHITE;
  }
  for(i = 1; i <= n; i++) {
    if(Node[i].color == WHITE) time = visit(M, Node, n, time, i);
  }
}

int visit(int M[][MAXN], NODE *Node, int n, int time, int u)
{
  int i, v;
  Node[u].color = GRAY;
  Node[u].d = ++time;
  for(v = 1; v <= n; v++) {
    if(M[u][v] == 1 && Node[v].color == WHITE) time = visit(M, Node, n, time, v);
  }
  Node[u].color = BLACK; /*finished*/
  Node[u].f = ++time;

  return time;
}


  

