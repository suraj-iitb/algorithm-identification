#include<stdio.h>

int a[101];
int b[101];

typedef struct
{
  int dg[101];
}g;

void bfs(g g[], int n)
{
  for(int i = 1; i <= n; i++)
    {
      a[i] = -1;
    }
  int head = 0, end = 0;
  b[end++] = 1;
  a[1] = 0;

  while(head != end)
    {
      int t = b[head++];
      for(int i = 1; i <= n; i++)
	{
	  if(a[i] == -1 && g[t].dg[i] == 1)
	    {
	      a[i] = a[t]+1;
	      b[end++] = i;
	    }
	}
    }
  
}

int main()
{
  int n1, c, b, d;
  scanf("%d", &n1);
  g g[n1+1];
  for(int i = 0 ; i < n1; i++)
    {
      scanf("%d%d", &c, &b);
      for(int j = 0; j < b; j++)
	{
	  scanf("%d", &d);
	  g[c].dg[d] = 1;
	} 
    }
  bfs(g, n1);

  for(int i = 1 ;i <= n1; i++)
    {
      printf("%d %d\n", i, a[i]);
    }
  
}

