#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define white 0
#define gray 1
#define black 2

int Q[MAX];
int head=0,tail=0;

int n,M[MAX][MAX];
int color[MAX],d[MAX]; //d[n]:始点sから各頂点iまでの最短経路をd[i]に記録。sからiへ到達不可能 な場合は、d[i]はINFINITY

//queueの実装
void enqueue(int x)
{
  int i;
  if(head == (tail+1)%MAX) exit(1); //FULL
  Q[tail] = x;
  tail = (tail+1) % MAX; //tail+1==MAX のときtail=０
}

int dequeue(void)
{
  int x;
  if(head==tail) exit(2); //EMPTY
  x = Q[head];
  head = (head+1)%MAX;
  return x;
}

void bfs(int s)
{
  int i,u,v;

  enqueue(s);

  for(i=0;i<n;i++)
    {
      d[i] = ((int)INFINITY);
      color[i] = white;
    }

  color[s] = gray;
  d[s] = 0;

  while(head!=tail)
    {
      u = dequeue();
      for(v=0;v<n;v++)
        {
          if(M[u][v] != 0 && color[v] == white)
            {
              color[v] = gray;
              d[v] = d[u] + 1;
              enqueue(v);
            }
        }
      color[u] = black;
    }

  for(i=0;i<n;i++)
    {
      printf("%d ",i+1);
      if(d[i] == ((int)INFINITY)) printf("-1\n");
      else printf("%d\n",d[i]);
    }
}

int main()
{
  int u,k,v;
  int i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        {
          M[i][j]=0;
        }
    }

  for(i=0;i<n;i++)
    {
      scanf("%d%d",&u,&k);
      u--;
      for(j=0;j<k;j++)
        {
          scanf("%d",&v);
          v--;
          M[u][v] = 1;
        }
    }

  bfs(0);

  return 0;
}

