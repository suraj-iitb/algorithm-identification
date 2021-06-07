#include<stdio.h>
#define N 100
#define W 0
#define G 1
#define B 2

int n, m[N][N];
int c[N], d[N], f[N], tt;

void dfs_visit(int u) {
	int v;
	c[u] = G;
	d[u] = ++tt;
	for (v = 0; v < n; v++) {
		if (m[u][v] == 0) {
			continue;
		}
		if (c[v] == W) {
			dfs_visit(v);
		}
	}
	c[u] = B;
	f[u] = ++tt;
}

void dfs() {
	int u;
	for(u = 0; u < n; u++) {
		c[u] = W;
	}
	tt = 0;
	for (u = 0; u < n; u++) {
		if (c[u] == W) {
			dfs_visit(u);
		}
	}

	for (u = 0; u < n; u++) {
		printf("%d %d %d\n", u + 1, d[u], f[u]);

	}
}

int main(void) {
	int u, v, k, i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			m[i][j]=0;
		}
	}
	for (i = 0; i < n; i++) {
		scanf("%d %d", &u, &k);
		u--;
		for (j = 0; j < k; j++) {
			scanf("%d", &v);
			v--;
			m[u][v] = 1;
		}
	}
	dfs();
	return 0;
}
