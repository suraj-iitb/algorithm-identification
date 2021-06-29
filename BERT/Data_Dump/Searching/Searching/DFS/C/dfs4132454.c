#include<stdio.h>

int a[101][101];
int t[101][2];
int num, n, count = 1;

void dfs(int);

int main ()
{
  int k, v;
  int i, j;
  
  scanf("%d", &n);

  for(i = 0; i < n; i++)
    {
      t[i][0] = 0;
      t[i][1] = 0;
    }
  
  for(i = 0; i < n; i++)
    {      
      scanf("%d%d", &num, &k);
      
      for(j = 0; j <= n; j++)
	{
	  a[num][j] = 0;
	  t[num][j] = 0;
	}
      
      
      for(j = 0; j < k; j++)
	{
	  scanf("%d", &v);
	  a[num][v] = 1;
	}
    }

  dfs(1);

 if(n*2 != count)
    {
      for(i = 1; i <= n; i++)
	{
	  if(t[i][0] == 0)
	    {
	    dfs(i);
	    }
	}
    }
  
  for(i = 1; i <= n; i++)
    {
      printf("%d %d %d\n", i, t[i][0], t[i][1]);
    }
      
  return 0;
}

void dfs(int start)
{
  int i;

  if(t[start][0] == 0)t[start][0] = count++;
  
  for(i = 1; i <= n; i++)
    {
  
      if(a[start][i] == 1 && t[i][0] == 0)
	{
	  dfs(i);
	}
    }
  if(t[start][1] == 0)t[start][1] = count++;

 
  return;
}

