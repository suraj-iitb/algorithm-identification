#include <stdio.h>

#define W -3
#define G -2
#define B -1
#define MAX 101 

void bfs(int);
void enq(int);
int deq(void);

int T[MAX][MAX];
int color[MAX];
int d[MAX];
int n;
int head,tail;
int Q[MAX];

int main()
{
  int i,j,youso,kazu,v;

  scanf("%d",&n);

  for(i=1;i<=n;i++)
    {
      scanf("%d%d",&youso,&kazu);

      for(j=0;j<kazu;j++)
	{
	  scanf("%d",&v);

	  T[i][v]=1;
	}
    }

  bfs(1);

  for(i=1;i<=n;i++)
    {
      printf("%d %d\n",i,d[i]);
    }
  
  return 0;
}

void bfs(int s)
{
  int i,u,v;

  for(i=1;i<=n;i++)
    {
      color[i]=W;
      d[i]=-1;
    }
  color[s]=G;
  d[s]=0;
  enq(s);

  while(head!=tail)
    {
      u=deq();
      
      for(v=1;v<=n;v++)
	{
	  if(T[u][v]==1)
	    {
	      if(color[v]==W)
		{
		  color[v]=G;
		  d[v]=d[u]+1;
		  enq(v);
		}
	    }
	}
      color[u]=B;
    }
}

void enq(int u)
{
  Q[tail]=u;
  tail++;
  if(tail==MAX)
    {
      tail=0;
    }
}

int deq(void)
{
  int u;
  u=Q[head];
  head++;
  if(head==MAX)
    {
      head=0;
    }
  return u;
}

