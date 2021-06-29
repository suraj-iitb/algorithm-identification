#include <stdio.h>
int n,M[100][100];
int ans[100][2];
int T = 0;
int k = 0;

void visit(int u)
{
	T++;
	ans[u][0]=T;
	for(int i=0;i<n;i++)
	{
		if(M[u][i]==1&&ans[i][0]==0)
		{
			visit(i);
		}
	}
	T++;
	ans[u][1]=T;
}

int main()
{
	int a,b,t;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		ans[i][0]=0;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a,&t);
		for(int j=0;j<n;j++)
		{
			M[a-1][j]=0;
		}
		for(int j=0;j<t;j++)
		{
			scanf("%d",&b);
			M[a-1][b-1]=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(ans[i][0]==0)
		{
			visit(i);
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d %d %d\n",i+1,ans[i][0],ans[i][1]);
	}
	return 0;
}
