#include<stdio.h>

int A[101][101],d[101],f[101],color[101],n,time;

#define WHITE 0
#define BLACK 1
#define GRAY 3


void dfs()
{
  int i;
  for(i=0;i<n;i++)
    {
      color[i]=WHITE;
      d[i]=0;
      f[i]=0;
    }
  time=0;
  for(i=0;i<n;i++)
    {
      if(color[i]==WHITE) visit(i);
    }
}

void visit(int u)
{
  int i;
  color[u]=GRAY;
  d[u]=++time;
  for(i=0;i<n;i++)
    {
      if(A[u][i]==0) continue;
      if(color[i]==WHITE) visit(i);
    }
  color[u]=BLACK;
  f[u]=++time;
}
  

int main()
{
  int i,j,m,k,l;
  scanf("%d",&n);

    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  A[i][j]=0;
	}
    }
  for(l=0;l<n;l++)
    {
      scanf("%d",&i);
      scanf("%d",&k);
      for(m=0;m<k;m++)
	{
	  scanf("%d",&j);
	  A[i-1][j-1]=1;
	}
    }

  dfs();

  for(i=0;i<n;i++)
    {
      printf("%d ",i+1);
      printf("%d ",d[i]);
      printf("%d\n",f[i]);
    }
  
  return 0;
}
