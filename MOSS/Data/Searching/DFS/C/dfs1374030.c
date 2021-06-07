#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_M (MAX_N * MAX_N)

typedef struct EDGE {
	int to;
	struct EDGE *next;
} edge;

int size;
edge buff[MAX_M];
edge *adj[MAX_N];

void add_edge(int u, int v) {
	edge *e = buff + size++;
	e->to = v;
	e->next = adj[u];
	adj[u] = e;
}

int t;
int d[MAX_N];
int f[MAX_N];

void dfs(int u) {
	edge *e;
	d[u] = t++;
	for(e = adj[u]; e != NULL; e = e->next) {
		if(d[e->to] == 0) dfs(e->to);
	}
	f[u] = t++;
}

int main() {
	int n;
	int u, k;
	int i, j;
	int v[MAX_N];

	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d %d", &u, &k);
		for(j = 0; j < k; ++j) {
			scanf("%d", v + j);
		}
		for(j = k - 1; j >= 0; --j) {
			add_edge(u - 1, v[j] - 1);
		}
	}

	t = 1;
	for(u = 0; u < n; ++u) {
		if(d[u] == 0) dfs(u);
		printf("%d %d %d\n", u + 1, d[u], f[u]);
	}

	return EXIT_SUCCESS;
}
