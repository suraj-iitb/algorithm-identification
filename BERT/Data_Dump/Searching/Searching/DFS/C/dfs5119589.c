#include<stdio.h>

int n;
int s[101];
int g[101];
int temp=0;
int z[101][101];

void dF(int m)
{
	int j,k;
	
	for(j=1;j<=n;j++)
	{
		if(z[m][j]==1)
		{
			for(k=1;k<=n;k++)
			{
				z[k][j]=2;
			}
			if(s[m]==0)
			{
				temp++;
				s[m]=temp;
			}
			dF(j);
		}
	}
	if(s[m]==0)
	{
		temp++;
		if(s[m]==0)
		{
			s[m]=temp;
		}
	}
	temp++;
	g[m]=temp;
}

int main(void)
{
	int x;
	int y;
	int k;
	int a;
	int b;
	int p[101];
	scanf("%d",&n);
	
	for(x=1;x<=n;x++)
	{
		p[x]=0;
		s[x]=0;
		g[x]=0;
		for(y=1;y<=n;y++)
		{
			z[x][y]=0;
		}
	}
	for(x=1;x<=n;x++)
	{
		scanf("%d%d",&a,&k);
		for(y=1;y<=k;y++)
		{
			scanf("%d",&b);
			z[a][b]=1;
			p[b]=1;
		}
		z[x][1]=2;
	}
	for(x=1;x<=n;x++)
	{
		if(x==1 || p[x]==0)
		{
			dF(x);
		}
	}
	for(x=1;x<=n;x++)
	{
		printf("%d %d %d\n",x,s[x],g[x]);
	}
	return 0;
}
