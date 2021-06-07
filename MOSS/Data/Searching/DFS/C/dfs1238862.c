#include <stdio.h>

int n;
int Adj[101][101] = { 0 };
int d[101] = { 0 };
int f[101] = { 0 };
int time = 0;

void DFS(int);

int main(void){
	int u, k, v;
	int i, j;

	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d %d", &u, &k);
		for (j = 1; j <= k; j++){
			scanf("%d", &v);
			Adj[u][v] = 1;
		}
	}

	for (i = 1; i <= n; i++){
		if (d[i] == 0)
			DFS(i);
	}
	for (i = 1; i <= n; i++){
		printf("%d %d %d\n", i, d[i], f[i]);
	}
	
	return 0;
}

void DFS(int u){
	int v;

	d[u] = ++time;
	for (v = 1; v <= n; v++){
		if ((d[v] == 0) && (Adj[u][v] == 1))
			DFS(v);
	}
	f[u] = ++time;
}
