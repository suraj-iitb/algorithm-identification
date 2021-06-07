#include<stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 100

int n,G[N][N],color[N],d[N],f[N];

void bfs(int x)
{
	int a,i,j;
	
	color[x] = GRAY;
	d[x] = 0;
	f[0] = x;
	
	for(;;)
	{
		
		a = f[0];
		
		for(i=0;f[i]!=-1;i++)
		{
			f[i] = f[i+1];
		}
		for(j=0;j<n;j++)
		{
			if(G[a][j]==0)
			{
				continue;
			}
			if(color[j]==WHITE)
			{
				color[j] = GRAY;
				d[j] = d[a] + 1;
				
				for(i=0;;i++)
				{
					if(f[i]==-1)
					{
						f[i] = j;
						break;
					}
				}
			}
		}
		
		color[a] = BLACK;
		
		if(f[0]==-1)
		{
			break;
		}
	}
}

int main(void)
{
	int i,j,a,b,c;
	
	a = 0;
	b = 0;
	c = 0;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		color[i] = WHITE;
		d[i] = -1;
		f[i] = -1;
		
		for(j=0;j<n;j++)
		{
			G[i][j] = 0;
		}
	}
	
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		for(j=0;j<b;j++)
		{
			scanf("%d",&c);
			G[a-1][c-1] = 1;
		}
	}
	
	bfs(0);
	
	for(i=0;i<n;i++)
	{
		 printf("%d %d\n", i+1, d[i]);
	}
	
	return 0;
}
