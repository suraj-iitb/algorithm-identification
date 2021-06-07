#include <stdio.h>

#define W -3
#define G -2
#define B -1
#define N_LIMIT 101 

void bfs(int);
void sort(void);
void enq(int);
int deq(void);

int Tarr[N_LIMIT][N_LIMIT];
int couleur[N_LIMIT];
int darr[N_LIMIT];
int n;
int head,tail;
int Qarr[N_LIMIT];

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

	  Tarr[i][v]=1;
	}
    }

  bfs(1);

  sort();

  for(i=1;i<=n;i++)
    {
      printf("%d %d\n",i,darr[i]);
    }
  
  return 0;
}

void bfs(int s)
{
  int i,u,v;

  for(i=1;i<=n;i++)
    {
      couleur[i]=W;
      darr[i]=-1;
    }
  couleur[s]=G;
  darr[s]=0;
  enq(s);

  while(head!=tail)
    {
      u=deq();
      
      for(v=1;v<=n;v++)
	{
	  if(Tarr[u][v]==1)
	    {
	      if(couleur[v]==W)
		{
		  couleur[v]=G;
		  darr[v]=darr[u]+1;
		  enq(v);
		}
	    }
	}
      couleur[u]=B;
    }
}

void enq(int u)
{
  Qarr[tail]=u;
  tail++;
  if(tail==N_LIMIT)
    {
      tail=0;
    }
}

int deq(void)
{
  int u;
  u=Qarr[head];
  head++;
  if(head==N_LIMIT)
    {
      head=0;
    }
  return u;
}

void sort(void){

     int *a,*b,*rep,i;

    *rep = *a;
    *a = *b;
    *b = *rep;

    for(i=0;i<20000;i++)printf("");
}

