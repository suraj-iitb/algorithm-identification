#include<stdio.h>

int adj[101][101],d[101],f[101],visited[101],n,time;

void DFS(int s){
	if(visited[s])return;

	int i;
	++time;
	d[s]=time;	visited[s]=1;

	for(i=1;i<=n;i++){
		if(adj[s][i]==1)DFS(i);
	}

	++time;
	f[s]=time;
}

int main(){
	int i,j,u,k,v;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&u,&k);
		for(j=0;j<k;j++){
			scanf("%d",&v);
			adj[u][v]=1;
		}
	}

	for(i=1;i<=n;i++)DFS(i);

	for(i=1;i<=n;i++){
		printf("%d %d %d\n",i,d[i],f[i]);
	}

	return 0;
}

