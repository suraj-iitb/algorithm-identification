#include<stdio.h>

int d[100];
int f[100];
int n;
int graph[100][100]={0};

int time=1;

int dfs(int node){
	d[node]=time++;
	int i,j;
	for(i=0;i<n;i++){
		if(graph[node][i]==1 && d[i]==0){
			dfs(i);
		}
	}
	f[node]=time++;
}

int main(void){
	int u, k, v;
	int i, j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&u,&k);
		for(j=0;j<k;j++){
			scanf("%d",&v);
			graph[u-1][v-1]=1;
		}
	}
	dfs(0);
	for(i=0;i<n;i++){
		if(d[i]==0){
			dfs(i);
		}
	}
	for(i=0;i<n;i++){
		printf("%d %d %d\n",i+1,d[i],f[i]);
	}
	return 0;
}
