#include <stdio.h>
#define N 100

int n,A[N][N];
int color[N],d[N],f[N];
int s;

void dfs_visit(u);
void dfs();

int main (void)
{
	int u,k,v;
	int i,j;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			A[i][j]=0;
		}
	}
	
	for(i=0;i<n;i++){
		scanf("%d %d",&u,&k);
		for(j=0;j<k;j++){
			scanf("%d",&v);
			A[u-1][v-1]=1;
		}
	}
	
	dfs();
	
	return 0;
}

void dfs_visit(int u)
{
	int v;
	
	color[u]=1;
	s++;
	d[u]=s;
	
	for(v=0;v<n;v++){
		if(A[u][v]==0){
			continue;
		}
		if(color[v]==0){
			dfs_visit(v);
		}
	}
	
	color[u]=2;
	s++;
	f[u]=s;
}

void dfs()
{
	int u;
	
	for(u=0;u<n;u++){
		color[u]=0;
	}
	s=0;
	
	for(u=0;u<n;u++){
		if(color[u]==0){
			dfs_visit(u);
		}
	}
	
	for(u=0;u<n;u++){
		printf("%d %d %d\n",u+1,d[u],f[u]);
	}
}
