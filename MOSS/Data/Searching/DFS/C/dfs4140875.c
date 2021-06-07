#include<stdio.h>
#define N 101
#define WHITE 0
#define BLACK 1
#define GRAY 2

typedef struct
{
  int  d,f,k,color;
}Depth;

int  B[N][N],n,cnt=0;
Depth D[N];

void DFS(int);
void Print();


int main()
{
  int i,j,u,v;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)B[i][j] = 0;
  }
  for(i=0;i<n;i++)
  {
    D[i].d = 0;
    D[i].color = WHITE;
    scanf("%d%d",&u,&D[i].k);
    u--;
    for(j=0;j<D[i].k;j++)
    {
      scanf("%d",&v);
      v--;
      B[u][v] = 1;
    }
  }

  Print();

  return 0;
}

void DFS(int u)
{
  int i;
  D[u].color = BLACK;
  D[u].d = ++cnt;
  for(i=0;i<n;i++)
  {
    if(B[u][i] == 0) continue;
    if(D[i].color == WHITE)DFS(i);
  }
  D[u].color = GRAY;
  D[u].f = ++cnt;
}

void Print()
{
  int i;
  for(i=0;i<n;i++)if(D[i].color == WHITE)DFS(i);
  for(i=0;i<n;i++)
  {
    printf("%d %d %d\n",i+1,D[i].d,D[i].f);
  }
}

