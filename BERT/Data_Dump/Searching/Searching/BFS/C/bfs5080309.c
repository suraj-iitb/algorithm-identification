#include<stdio.h>

int T[500][500];
int d[500];
int e[500];
int g=0;

void DFS(int x,int y,int n)
{
	int i;
	for(i=1; i<n+1; i++)
	{
		if(T[x][i]==1 && d[i]>y)
		{
			d[i]=y;
			e[i]=1;
			DFS(i,y+1,n);
		}
	}
}
void cheak(int n)
{
	int i;
	for(i=2; i<n+1; i++)
	{
		if(e[i]==0)
		{
			d[i]=-1;
		}
	}
}
	

int main(void)
{
	int n,i,j,id,k,a,b;
	
	scanf("%d",&n);

	for(i=1; i<n+1; i++)
	{
		for(j=1; j<n+1; j++)
		{
			T[i][j]=0;
		}
		d[i+1]=10000;
		e[i+1]=0;
	}
	
	int A[n];
 
	for(i=0; i<n; i++)
	{
		scanf("%d ",&id);
		scanf("%d ",&k);
		for(j=0; j<k; j++)
		{
			scanf("%d",&A[j]);
			T[id][A[j]]=1;
		}
	}

	DFS(1,1,n);
	cheak(n);
	
	for(i=1; i<n+1; i++)
	{
		printf("%d %d\n",i,d[i]);
	}
	return 0;
}
