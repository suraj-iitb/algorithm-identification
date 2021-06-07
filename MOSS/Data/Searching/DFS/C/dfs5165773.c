#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK -1

void dfs(void);
void visit(int);
void push(int);
int pop(void);
int next(int);

int n, M[MAX + 1][MAX + 1], color[MAX + 1], stack[MAX + 1], d[MAX + 1], f[MAX + 1];
int top = 0, nowtime = 0;

int main()
{
  int u, k;
  int i, j;

  scanf("%d", &n);
  
  for(i = 1 ; i <= n ; i++)
    {
      scanf("%d", &u);
      scanf("%d", &k);
      for(j = 1 ; j <= k ; j++)
	{
	  scanf("%d", &M[u][j]);
	}
    }

  dfs();

  for(i = 1 ; i <= n ; i++) printf("%d %d %d\n", i, d[i], f[i]);

  return 0;
}

void dfs()
{
  int i;

  for(i = 1 ; i <= n ; i++)
    {
      color[i] = WHITE;
    }
  
  for(i = 1 ; i <= n ; i++)
    {
      if(color[i] == WHITE) visit(i);
    }
}

void visit(int r)
{
  int u, v, k;
 
  push(r);
  color[r] = GRAY;
  d[r] = ++nowtime;

  while(top > 0)
    {
      u = stack[top];
      v = next(u);
      if(v != NULL)
	{
	  if(color[v] == WHITE)
	    {
	      push(v);
	      color[v] = GRAY;
	      d[v] = ++nowtime;
	    }
	}
      else
	{
	  pop();
	  color[u] = BLACK;
	  f[u] = ++nowtime;
	}
    }
}

void push(int s)
{
  if(top == MAX) exit(1);

  top++;
  stack[top] = s;
}

int pop(void)
{
  if(top == 0) exit(2);

  top--;

  return stack[top + 1];
}

int next(int u)
{
  int i;

  for(i = 1 ; M[u][i] != NULL ; i++)
    {
      if(color[M[u][i]] == WHITE) return M[u][i];
    }

  return NULL;
}

