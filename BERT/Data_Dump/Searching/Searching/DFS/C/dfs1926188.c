#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
void dfs();
void visit(int);
int color[101];
int graph[101][101];
int d[101];
int f[101];
int n;
int time;
int main()
{
  
  int i,j,x,y,z;
  scanf("%d",&n);

  for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
	{
	  graph[i][j]=0;
	}
    }

  for(i=1;i<=n;i++)
    {
      scanf("%d%d",&x,&y);
      
      for(j=1;j<=y;j++)
	{
	  scanf("%d",&z);
	  
	  graph[x][z]=1;
	    }
    }

  dfs();

  return 0;
}

void dfs()
{
  int i;
  for(i=1;i<=n;i++)
    color[i]=WHITE;

  time =0;
  for(i=1;i<=n;i++)
    if(color[i]==WHITE)
      visit(i);

  for(i=1;i<=n;i++)
    {
      printf("%d %d %d\n",i,d[i],f[i]);
    }
}

void visit(int i)
{
  int j;
  color[i] = GRAY;
  d[i]=++time;
  for(j=1;j<=n;j++)
    {
      if(color[j]==WHITE && graph[i][j]!=0){
	visit(j);
      }
	  }
  color[i] = BLACK;
  f[i] = ++time;
}
