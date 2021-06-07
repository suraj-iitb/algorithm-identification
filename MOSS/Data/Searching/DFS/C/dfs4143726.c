#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[N][N];
int color[N], d[N], f[N], tt;

void dfs_visit(int u) {
	int v;
	color[u] = GRAY;
	d[u] = ++tt;
	for (v = 0; v < n; v++) {
		if (M[u][v] == 0)continue;
		if (color[v] == WHITE) {
			dfs_visit(v);
		}
	}
	color[u] = BLACK;
	f[u] = ++tt;
}


int main() {
	int u, v, k, i, j,m;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)M[i][j] = 0;
	}

	for (i = 0; i < n; i++) {
		scanf("%d %d", &u, &k);
		u--;
		for (j = 0; j < k; j++) {
			scanf("%d", &v);
			v--;
			M[u][v] = 1;
		}
	}

	for (m = 0;  m< n; m++)color[m] = WHITE;
	tt = 0;

	for (m = 0; m < n; m++) {
		if (color[m] == WHITE)dfs_visit(m);
	}
	for (m = 0; m < n; m++) {
		printf("%d %d %d\n", m + 1, d[m], f[m]);
	}

	return 0;
}

