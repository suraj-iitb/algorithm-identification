#include<stdio.h>

int adj[101][101]={0};
int d[101]={0},f[101]={0},status[101];
int n,t=0;

void dfs(int u){
	int i;
	
	status[u]=0;
	t++;
	d[u]=t;
	
	for(i=1;i<n+1;i++){
		if(adj[u][i]==1 && status[i]==-1){
			status[i]=0;
			dfs(i);
		}
	}
	
	t++;
	f[u]=t;
	status[u]=1;
}

int main(void){
	int i,j,u,k,v;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d %d",&u,&k);
		
		for(j=0;j<k;j++){
			scanf("%d",&v);
			adj[u][v]=1;
		}
	}
	
	for(i=1;i<n+1;i++){
		status[i]=-1;
	}
	
	for(i=1;i<n+1;i++){
		if(status[i]==-1){
			dfs(i);
		}
	}
	
	for(i=1;i<n+1;i++){
		printf("%d %d %d\n",i,d[i],f[i]);
	}
	
	return 0;
}
