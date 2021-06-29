#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,M[100][100] = {};
int color[100] = {}, d[100], f[100], t=0;

void dfs(void);

void dfs_visit(int);

int main() {
	int u,v, k,i,j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &u, &k);
		u--;
		for (j = 0; j < k; j++) {
			scanf("%d", &v);
			v--;
			M[u][v]=1;
		}
	}
	dfs();
	return 0;
}

void dfs(void) {
	int u;
	for (u = 0; u < n; u++) {
		if (color[u] == WHITE) {
			dfs_visit(u);
		}
	}
	for (u = 0; u < n; u++) {
		printf("%d %d %d\n", u + 1, d[u], f[u]);
	}
}

void dfs_visit(int u) {
	int v;
	color[u] = GRAY;
	d[u] = ++t;
	for (v = 0; v < n; v++) {
		if (M[u][v] == 0) {
			continue;
		}
		if (color[v] == WHITE) {
			dfs_visit(v);
		}
	}
	color[u] = BLACK;
	f[u] = ++t;
}
