#include<stdio.h>
#define N 101

int MAX = (1<<21), n, A[N][N], num[N], d[N], f[N], count, Q[N*2], head, tail;

void init()
{
  head = tail = 1;
}

void enqueue(int x)
{
  Q[tail++] = x;
}

int empty()
{
  return head == tail;
}

int dequeue()
{
  int x = Q[head++];
  return x;
}

void bfs(int s){
  int i, x, y;
  init();
  enqueue(s);
  for ( i = 0; i < n; i++ )d[i] = MAX;
  d[s] = 0;
  while(!empty())
    {
      x = dequeue();
      for ( y = 0; y < n; y++ )
	{
	  if ( A[x][y] == 0 )
	    {
	      continue;
	    }
	  if ( d[y] != MAX )
	    {
	      continue;
	    }
	  d[y] = d[x] + 1;
	  enqueue(y);
	}
    }
  
  for ( i = 0; i < n; i++ )
    {
      printf("%d %d\n", i+1,((d[i]==MAX)?(-1):d[i]));
    }
  
}

int main(){
  int  x, y, z, i, j;

  scanf("%d", &n);

  for ( i = 0; i <n; i++ )
    {
      for ( j = 0; j <n; j++ )
	{
	  A[i][j] = 0;
	}
    }
  
  for ( i = 0; i < n; i++ )
    {
      scanf("%d %d", &x, &z);
   
      for ( j = 0; j < z; j++ )
	{
	  scanf("%d", &y);
     
	  A[x-1][y-1] = 1;
	}
    }
 
  bfs(0);

  return 0;
}
