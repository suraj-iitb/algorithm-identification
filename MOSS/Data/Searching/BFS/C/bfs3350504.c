#include<stdio.h>
#include<stdlib.h>

#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL -1

void enqueue(int);
int dequeue(void);
void BFS(int);

int n,Q[MAX],head=1,tail=1;
int C[MAX],k[MAX],A[MAX][MAX],d[MAX];

int main()
{
  int i,j,id;

  scanf("%d",&n);

  for(i = 1 ; i <= n ; i++)
    {
      scanf("%d",&id);
      scanf("%d",&k[id]);
      for(j = 1 ; j <= k[id] ; j++)
	{
	  scanf("%d",&A[id][j]);
	}
    }

  for(i = 1 ; i <= n ; i++) //データの初期化
    {
      C[i] = WHITE;
      d[i] = NIL;
    }

  BFS(1);

  for(i = 1 ; i <= n ; i++)
    {
      printf("%d %d\n",i,d[i]);
    }
  
  return 0;
}

void BFS(int s)
{
  int v,j,u;
 
  C[s] = GRAY;
  d[s] = 0;
  enqueue(s);

  while(u = dequeue())
    {
      for(j = 1 ; j <= k[u] ; j++)
	{
	  v = A[u][j];
	  if(C[v] == WHITE)
	    {
	      C[v] = GRAY;
	      d[v] = d[u] + 1;
	      enqueue(v);
	    }
	    
	}
      C[u] = BLACK;
    }

  return;
}

void enqueue(int x)
{
  if(head == tail + 1 || (head == 1 && tail == n)) exit(2);
  Q[tail] = x;
  if(tail == n)
    {
      tail = 1;
    }
  else tail++;

  return;
}

int dequeue()
{
  int x;
  
  if(head == tail) return 0;
  x = Q[head];
  if(head == n)
    {
      head = 1;
    }
  else head++;

  return x;
}

