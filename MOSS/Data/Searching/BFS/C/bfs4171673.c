#include <stdio.h>

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF (-1000)

int n;
int d[MAX],c[MAX],M[MAX][MAX];
int Q_tail=0,Q_head=0,Q[MAX];

void enqueue(int s)
{
  Q[Q_tail]=s;
  if(Q_tail + 1 == n)
  Q_tail=0;
  else Q_tail++;
}

int dequeue()
{
  int x;
  x=Q[Q_head];
  if(Q_head+1==n) Q_head=0;
  else Q_head++;
  return x;
}

void bfs(int s)
{
  int u;

  enqueue(s);
  for(int i=0;i<n;i++)
  {
    d[i]=INF;
  }
  d[s]=0;
  while(Q_tail!=Q_head)
  {
    u=dequeue();
    for(int v=0;v<n;v++)
    {
      if(M[u][v]&&c[v]==WHITE)
      {
        c[v]=GRAY;
        d[v]=d[u]+1;
        enqueue(v);
      }
      c[u]=BLACK;
    }
  }

  for(int i=0;i<n;i++)
  {
    printf("%d ",i+1);
    if(d[i]==INF) printf("-1\n");
    else printf("%d\n",d[i]);
  }
}

int main()
{
  int u;
  int k;
  int v;

  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      M[i][j]=0;
    }
  }

  for(int i=0;i<n;i++)
  {
    scanf("%d%d",&u,&k);
    u--;
    for(int j=0;j<k;j++)
    {
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }

  bfs(0);

  return 0;
}

