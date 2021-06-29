#define dbg(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#define dpri(x) dbg(#x ": %d\n", x)
#define dprs(x) dbg(#x ": %s\n", x)
#include <stdio.h>
typedef long long ll;
const int MYINF = 1e9+7;
typedef int bool;
const bool true = 1;
const bool false = 0;

#define MAX_N 128
int G[MAX_N][MAX_N];
int n;
int sz[MAX_N];
int d[MAX_N];
int f[MAX_N];

int t;
void dfs(int v) {
	int i;
	if (d[v]) return;
	d[v] = t++;
	for (i = 0; i < sz[v]; i++) {
		dfs(G[v][i]);
	}
	f[v] = t++;
}

int main(int argc, char **argv)
{
	int i, j, u, k, v;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &u, &k);
		sz[u] = k;
		for (j = 0; j < sz[u]; j++) {
			scanf("%d", &v);
			G[u][j] = v;
		}
	}


	t = 1;
	for (i = 1; i <= n; i++) {
		dfs(i);
	}

	for (i = 1; i <= n; i++) {
		printf("%d %d %d\n", i, d[i], f[i]);
	}

	return 0;
}
