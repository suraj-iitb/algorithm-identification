#include<stdio.h>

#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

void visit(void);
void enqueue(int);
int dequeue(void);
int isEmpty(void);
int isFull(void);

int n;
int head = 0,tail = 0;
int graph[N][N],color[N],d[N],que[N];

int main()
{
  int i,j;
  int v1,v2,m;

  scanf("%d",&n);
  //n++;

  for(i = 1; i < n; i++)
    {
      for(j = 1; j < n; j++)
	{
	  //d[i] = -1;
	  color[i] = WHITE;
	  graph[i][j] = 0;
	}
    }
  color[0] = GRAY;
  d[0] = 0;
  enqueue(0);
  

  for(i = 0; i < n; i++)
    {
      scanf(" %d %d",&v1,&m);
      for(j = 0; j < m; j++)
	{
	  scanf(" %d",&v2);
	  graph[v1 - 1][v2 - 1] = 1;
	}
    }
  
  for(i = 0; i < n; i++)
    {
      if(graph[0][i] == 1)
	{
	  color[j] = WHITE;
	}
    }

  visit();
  
  
}



void visit(void)
{
  int i,u;
  
  while(1)
    {
      if(head == tail)break;
      u = dequeue();

      for(i = 0; i < n; i++)
	{
	  if(graph[u][i] == 1 && color[i] == WHITE)
	    {
	      color[i] = GRAY;
	      d[i] = d[u] + 1;
	      enqueue(i);
	    }
	  color[u] = BLACK;
	}
    }

  for(i = 0; i < n; i++)
    {
      if(color[i] == BLACK)
	{
	  printf("%d %d\n",i+1,d[i]);
	}
      else printf("%d -1\n",i+1);
    }
}




  
  void enqueue(int n)
{
  int flag;
  flag = isFull();
  if(flag == 0)
    {
      if(tail + 1 == N)
	{
	  que[tail] = n;
	  tail = 0;
	}
      else
	{
	  que[tail] = n;
	  tail++;
	}
    }
}

int dequeue(void)
{
  int n;
  int flag;
  flag = isEmpty();
  if(flag == 0)
    {
      if(head + 1 == N)
	{
	  n = que[head];
	  head = 0;
	}
      else
	{
	  n = que[head];
	  head++;
	}
    }
  return n;
}

int isEmpty(void)
{
  if(head == tail)return 1;
  else return 0;
}

int isFull(void)
{
  if((tail + 1)% N == head)return 1;
  else return 0;
}

