#include<stdio.h>
#define N 101


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
    D[i].color = 0;
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
  D[u].color = 1;
  D[u].d = ++cnt;
  for(i=0;i<n;i++)
  {
    if(B[u][i] == 0) continue;
    if(D[i].color == 0)DFS(i);
  }
  D[u].color = 2;
  D[u].f = ++cnt;
}

void Print()
{
  int i;
  for(i=0;i<n;i++)if(D[i].color == 0)DFS(i);
  for(i=0;i<n;i++)
  {
    printf("%d %d %d\n",i+1,D[i].d,D[i].f);
  }
}

