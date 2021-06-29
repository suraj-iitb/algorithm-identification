#include <stdio.h>
#define W 0
#define G 1
#define B 2

int M[100][100],n,d[100],que[100],qf=0,qb=0,c[100];
void enque(int x)
{
  que[qb]=x;
  qb=(qb+1)%100;
}

int deque(void)
{
  int x;
  x=que[qf];
  qf=(qf+1)%100;
  return x;
}

void bfs(void)
{
  int u,v;
  for(u=0;u<n;u++)
    {
      d[u]=-1;
      c[u]=W;
    }
  c[0]=G;
  d[0]=0;
  enque(0);
  while(qf!=qb)
    {
      u=deque();
      for(v=0;v<n;v++)
	{
	  if(M[u][v]==1&&c[v]==W)
	    {
	      c[v]=G;
	      d[v]=d[u]+1;
	      enque(v);
	    }
	}
      c[u]=B;
    }

  for(u=0;u<n;u++)
    {
      printf("%d %d\n",u+1,d[u]);
    }
}
  

int main()
{
  int i,j;
  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  M[i][j]=0;
	}
    }

  int k,u,v;
  
  for(i=0;i<n;i++)
    {
      scanf("%d",&u);
      scanf("%d",&k);
      for(j=0;j<k;j++)
	{
	  scanf("%d",&v);
	  M[u-1][v-1]=1;
	}
    }

  bfs();

  return 0;
}

