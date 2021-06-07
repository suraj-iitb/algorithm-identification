//recursion dfs

#include <stdio.h>

#define N 100
#define white 0
#define gray 1
#define black 2

int n, M[N][N];
int color[N], d[N], f[N], tt;

//recursion

void dfs_visit(int u) {
	int v;
	color[u] = gray;
	d[u] = tt++;
	for (v = 0; v < n; v++) {
		if (M[u][v] && color[v] == white) {
			dfs_visit(v);
		}
	}
	color[u] = black;
	f[u] = tt++;
}

void dfs() {
	int u;
	for (u = 0; u < n; u++) {
		color[u] = white;
		tt = 1;

	}

	for (u = 0; u < n; u++) {
		if (color[u] == white) dfs_visit(u);
	}

	for (u = 0; u < n; u++) {
		printf("%d %d %d\n", u+1, d[u], f[u]);
	}
}
int main() {
	int u, v, k;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			M[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &u, &k);
		u--;
		for (int j = 0; j < k; j++) {
			scanf("%d", &v);
			v--;
			M[u][v] = 1;
		}
	}

	dfs();
	return 0;
}
