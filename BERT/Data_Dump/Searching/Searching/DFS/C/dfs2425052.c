#include <stdio.h>

#define N 101

int M[N][N] = {};
int d[N];
int f[N];
char color[N];
int n;
int time;

void visit(int u) {
	int i;

	color[u] = 'G';
	d[u] = ++time;
	for (i=1;i<=n;i++) {
		if (M[u][i] == 1 && color[i] == 'W') {
			visit(i);
		}
	}
	color[u] = 'B';
	f[u] = ++time;
}

void dfs() {
	int i;
	for (i=1;i<=n;i++) color[i] = 'W';
	time = 0;
	for (i=1;i<=n;i++) if (color[i] == 'W') visit(i);
}

int main() {
	int i,j;
	int u,k,v;

	scanf("%d", &n);
	for (i=1;i<=n;i++) {
		scanf("%d%d",&u,&k);
		for (j=1;j<=k;j++) {
			scanf("%d",&v);
			M[u][v] = 1;
		}
	}

	dfs();

	for (i=1;i<=n;i++) {
		printf("%d %d %d\n",i,d[i],f[i]);
	}

	return 0;
}
