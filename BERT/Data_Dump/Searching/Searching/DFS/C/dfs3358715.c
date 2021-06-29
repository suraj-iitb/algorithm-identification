#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
int color[101];
int A[101][101];
int d[101];
int f[101];
int time, n;

void visit(int u) {
	int i;
	color[u] = GRAY;
	d[u] = ++time;
	for (i = 1; i <= n; i++) {
		if (A[u][i] == 1) {
			if (color[i] == WHITE) visit(i);
		}
	}
	color[u] = BLACK;
	f[u] = ++time;
}

void dfs() {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (A[i][j] == 1) {
				if (color[i] == WHITE) visit(i);
			}
		}
	}
}

int main() {
	int i, j, v, u, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &u, &k);
		for (j = 0; j < k; j++) {
			scanf("%d", &v);
			A[u][v] = 1;
		}
	}
	dfs();
	for (i = 1; i <= n; i++) {
		printf("%d %d %d\n", i, d[i], f[i]);
	}
}
