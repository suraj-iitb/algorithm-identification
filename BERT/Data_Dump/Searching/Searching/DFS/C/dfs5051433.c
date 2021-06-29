#include<stdio.h>

int T[500][500];
int d[500];
int f[500];
int g=0;

void DFS(int x,int n)
{
	int i;
	g++;
	d[x]=g;
	for(i=1; i<n+1; i++)
	{
		if(d[i]==0 && T[x][i]==1)
		{
			DFS(i,n);
		}
	}
	g++;
	f[x]=g;
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
		d[i]=0;
		f[i]=0;
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
	
	for(i=1; i<n+1; i++)
	{
		if(d[i]==0)
		{
			DFS(i,n);
		}
	}
	
	for(i=1; i<n+1; i++)
	{
		printf("%d %d %d\n",i,d[i],f[i]);
	}
	
	return 0;
}
