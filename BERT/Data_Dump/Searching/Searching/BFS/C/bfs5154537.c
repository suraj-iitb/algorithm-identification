#include<stdio.h>

#define MAX 101
#define WHITE -3
#define GRAY -2
#define BLACK -1

void bfs(int);
void enq(int);
int deq(void);

int n;/*頂点数*/
int M[MAX][MAX];/*行＝要素、列＝繋がっている要素*/
int color[MAX];/*色分け用の配列*/
int d[MAX];
int head,tail;
int Q[MAX];

int main()
{
	int i, j, element, number, v;

	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&element,&number);

		for(j=0;j<number;j++)
		{
			scanf("%d",&v);
			M[i][v]=1;
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

	for(i=0;i<=n;i++)
	{
		color[i]=WHITE;
		d[i]=-1;
	}
	color[s]=GRAY;
	d[s]=0;
	enq(s);

	while(head!=tail)
	{
		u=deq();

		for(v=1;v<=n;v++)
		{
			if(M[u][v]==1)
			{
				if(color[v]==WHITE)
				{
					color[v]=GRAY;
					d[v]=d[u]+1;
					enq(v);
				}
			}
		}
		color[u]=BLACK;
	}
}

void enq(int u)
{
	Q[tail]=u;
	tail++;
	if(tail == MAX)tail=0;
}

int deq(void)
{
	int u;
	u=Q[head];
	head++;
	if(head == MAX)head=0;

	return u;
}







































