#include <stdio.h>

#define MAX_N 101
#define INF 100000000

int n, G[MAX_N][MAX_N], vis[MAX_N], size[MAX_N];

void dfs(int p, int t){
	vis[p] = t;
	for (int ix = 1; ix <= size[p]; ix++) 
		if ( t+1 < vis[G[p][ix]] ) 
			dfs(G[p][ix], t+1);
}

int main(){
	int u;
	scanf("%d", &n);
	for (int ix = 1 ; ix <= n; ix++){
		vis[ix] = INF;
		scanf("%d", &u);
		scanf("%d", &size[u]);
		for(int jx = 1; jx <= size[u]; jx++) 
			scanf("%d", &G[u][jx]);
	}
	dfs(1, 0);
	for (int ix = 1 ; ix <= n; ix++) 
		printf("%d %d\n",ix,(vis[ix] == INF) ? -1 : vis[ix]);
	return 0;
}
