#include<stdio.h>

int timer;
int n;

typedef struct
{
  int iudgment;
  int time;
  int finish;
  int position[101];
}graph;

void check(int t, graph g[])
{
  g[t].iudgment = 1;
  g[t].time = ++timer;
  for(int i = 0; i < n; i++)
    {
      if(g[t].position[i] == 1)
	{
	  if(g[i].iudgment == 0)
	    {
	      check(i, g);
	    }
	}
    }
  g[t].iudgment = 2;
  g[t].finish = ++timer;
}

int main()
{
  int a, b, c;
  scanf("%d", &n);
  graph g[n];
  timer = 0;
  for(int i = 0; i < n; i++)
    {
      g[i].iudgment = 0;
      for(int j = 0; j < n; j++)
	{
	  g[i].position[j] = 0;
	}
    }
  for(int i = 0; i < n; i++)
    {
      scanf("%d %d", &a, &b);
      for(int j = 0; j < b; j++)
	{
	  scanf("%d", &c);
	  g[a-1].position[c-1] = 1;
	}
    }
  for(int i = 0; i < n; i++)
    {
      if(g[i].iudgment == 0)
	{
	  check(i, g);
	}
    }

  for(int i = 0 ; i < n; i++)
    {
      printf("%d %d %d\n", i+1, g[i].time, g[i].finish);
    }
}

