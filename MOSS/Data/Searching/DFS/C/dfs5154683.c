#include<stdio.h>

void visit(int,int);
void dfs(int);

#define WHITE 0
#define GRAY 1
#define BLACK 2

int graph[101][101];
int d[101],f[101],color[101];
int t = 0;

int main()
{
  int i,j,n,id,num,count;
  scanf("%d",&n);
  n++;
 for(i = 1; i < n; i++)
   {
     for(j = 1; j < n; j++)
       {
	 graph[i][j] = 0;
       }
   }
 
  
  for(i = 1; i < n; i++)
    {
      scanf(" %d %d",&id,&count);
      for(j = 0; j < count; j++)
	{
	  scanf("%d",&num);
	  graph[id][num] = 1;
	}
    }
  /*for(i = 1; i < n; i++)
    {
      for(j = 1; j < n-1; j++)
	{
	  printf("%d ",matrics[i][j]);
	}
      printf("%d\n",matrics[i][n-1]);
      }*/
  
  dfs(n);

  for(i = 1; i < n; i++)
    {
      printf("%d %d %d\n",i,d[i],f[i]);
    }
  
  return 0;
}

void dfs(int n)
{
  int i;
  for(i = 1; i < n; i++)
    {
      if(color[i] == WHITE)visit(i,n);
    }
}

void visit(int u,int n)
{
  int i;
  color[u] = GRAY;
  t++;
  d[u] = t;

  for(i = 1; i < n; i++)
    {
      if(graph[u][i] == 1 && color[i] == WHITE)visit(i,n);
    }

  color[u] = BLACK;
  t++;
  f[u] = t;
}

						 
    

