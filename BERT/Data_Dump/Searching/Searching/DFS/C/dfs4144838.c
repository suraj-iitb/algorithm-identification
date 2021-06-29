#include<stdio.h>

int A[101][101],d[101],f[101],visited[101],n,time;

void dfs(int r){
	int i;
	if(visited[r]!=0)
		return ;
	d[r]=++time;
		visited[r]=1;

	for(i=1;i<=n;i++){
		if(A[r][i]==1)
			dfs(i);
	}
	f[r]=++time;
}

int main(){
	int i,j,u,k,v;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&u,&k);
		for(j=0;j<k;j++){
			scanf("%d",&v);
			A[u][v]=1;
		}
	}
	for(i=1;i<=n;i++)
		dfs(i);
	for(i=1;i<=n;i++)
		printf("%d %d %d\n",i,d[i],f[i]);
	return 0;
}
