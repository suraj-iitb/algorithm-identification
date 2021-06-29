#include <stdio.h>

#define N 100
#define INFTY 2097152

void enqueue(int);
int dequeue(void);
void bfs(int);

int M[N][N];
int d[N];
int queue[2*N];

int n,i,j;
int head = 1,tail=1;


int main(void)
{
  int k;
  int u,v;

  scanf("%d",&n);

  for(i = 0;i < n;i++)
  {
    for(j = 0;j < n;j++)
    {
      M[i][j] = 0;
    }
  }

  for(i = 0;i < n;i++)
  {
    scanf("%d %d",&u,&k);
    u--;

    for(j = 0;j < k;j++)
    {
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }
  }


  bfs(0);

  return 0;
}




void enqueue(int q)
{
  queue[tail++] = q;
}


int dequeue()
{
  return queue[head++];
}


void bfs(int q)
{
  int u,v;

  enqueue(q);

  for(i = 0;i < n;i++)
  {
   d[i] = INFTY;
  }
  d[q] = 0;

 while(head != tail)
 {
   u = dequeue();
   for(v = 0;v < n;v++)
   {
     if(M[u][v] == 0)
     {
       continue;
     }
     if(d[v] != INFTY)
     {
       continue;
     }
     d[v] = d[u] + 1;
     enqueue(v);
   }
 }

 for(i = 0;i < n;i++)
 {
   printf("%d ",i+1);
   if(d[i] == INFTY)
   {
     puts("-1");
   }
   else
   {
     printf("%d\n",d[i]);
   }
 }
}

