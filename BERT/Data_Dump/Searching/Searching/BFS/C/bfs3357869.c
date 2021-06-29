#include<stdio.h>
#define INFTY 100000000

int n,d[105][105],color[105];

void bfs(int G,int s)
{
  int i;
  for(i=0;i<n;i++)
    {
      if(d[G][i+1]==1 && color[i+1]>s)
        {
          color[i+1]=s;
          bfs(i+1,s+1);
        }
    }
}

int main()
{
  int i,j,k,m,l;
  for(i=0;i<100;i++)
    {
      color[i+1]=INFTY;
    }
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d%d",&k,&m);
      for(j=0;j<m;j++)
        {
          scanf("%d",&l);
          d[k][l]=1;
        }
    }
  color[1]=0;
  bfs(1,1);
  for(i=0;i<n;i++)
    {
      printf("%d ",i+1);
      if(color[i+1]==INFTY)
        printf("-1");
      else printf("%d",color[i+1]);
      printf("\n");
    }
  return 0;
}

