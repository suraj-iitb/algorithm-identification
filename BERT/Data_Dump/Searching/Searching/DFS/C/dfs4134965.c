#include <stdio.h>
#define N 100
#define WHITE 0
#define BLACK 1
#define GRAY 2

int represent[N][N],u,color[N],f[N],d[N],tt;

void dfs_cal(int n)
{
  int v;
  color[n]=GRAY;
  d[n]=++tt;
  for(v=0;v<u;v++)
    {
      if(represent[n][v]==0)continue;
      if(color[v]==WHITE)
	{
	  dfs_cal(v);
	}
    }
  color[n]=BLACK;
  f[n]=++tt;
}

void dfs(void)
{
  int i,j,k;
  for(i=0;i<u;i++)
    color[i]=WHITE;
  tt=0;
  for(i=0;i<u;i++)
    {
      if(color[i]==WHITE)dfs_cal(i);
    }
  for(i=0;i<u;i++)
    {
      printf("%d %d %d\n",i+1,d[i],f[i]);
    }
}

int main()
{
  int i,j,k,ade,retu;
 while(1)
    {
      scanf("%d",&u);
      if(u>=1 && u<=N)
	break;
    }
  for(i=0;i<u;i++)
    {
      for(j=0;j<u;j++)
	{
	  represent[i][j]=0;
	}
    }
  for(i=0;i<u;i++)
    {
      scanf("%d",&ade);
      scanf("%d",&k);
      for(j=0;j<k;j++)
	{
	  scanf("%d",&retu);	  
	  represent[ade-1][retu-1]=1;
	}
    }
  dfs();
  return 0;
}

