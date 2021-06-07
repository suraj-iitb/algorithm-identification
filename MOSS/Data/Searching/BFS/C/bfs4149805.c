#include<stdio.h>
#define MAX 150
#define NIL -1

int graph[MAX][MAX];
int a[MAX];
int n;
int Que[10000];
int head=0, tail=0;

void enQue(int q);
int deQue(void);
int size(void);
void bfs(int i);

int main()
{
  int b;
  int k;
  int i,j;
  int c;

  scanf("%d",&n);
  for(i=0;i<MAX;i++)
  { 
      a[i]=NIL;
  }
  for(i=0;i<n;i++)
  {
    scanf("%d",&b);
    scanf("%d",&k);
    for(j=0;j<k;j++)
    {
      scanf("%d",&c);
      graph[b-1][c-1]=1;
    } 
  }
  a[0]=0;
  bfs(0);
  while(size()!=0)
  {
    bfs(deQue());
  }
  for(i=0;i<n;i++)
  {
    printf("%d %d\n",i+1,a[i]);
  }
return 0;
}

void enQue(int q)
{
  Que[head]=q;
  head++;
}

int deQue(void)
{
  tail++;
  return Que[tail-1];
}

int size(void)
{
  return head-tail;
}


void bfs(int i)
{
  int j;
  for(j=0; j<n; j++)
  {
    if(graph[i][j]==1 && a[j]==NIL)
    {
      a[j]=a[i]+1;
      enQue(j);
    }
  }
}

