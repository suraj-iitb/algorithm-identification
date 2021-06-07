#include<stdio.h>
int n;
int visited[102]= {0};
int M[102][102]= {0};
int time=0;
int t1[102]= {0},t2[102]= {0};
void dfs(int v) {
	time++;
	t1[v]=time;
	visited[v]=1;
	//printf(" %d%d ",v,visited[v]);
	int i;
	for(i=1; i<=n; i++) {
		if(M[v][i]&&(!visited[i]))
			dfs(i);
	}
	time++;
	t2[v]=time;
	return;
}
int main() {
	scanf("%d",&n);
	int i,j,k,u,v;
	for(i=1; i<=n; i++) {
		scanf("%d%d",&u,&k);
		for(j=1; j<=k; j++) {
			scanf("%d",&v);
			M[u][v]=1;
		}
	}
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			if(M[i][j]&&(!visited[i])) {
				dfs(i);
			}
		}
	}
	for(k=1; k<=n; k++)
		printf("%d %d %d\n",k,t1[k],t2[k]);
	return 0;
}

