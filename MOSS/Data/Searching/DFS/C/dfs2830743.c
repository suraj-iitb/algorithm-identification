// AOJ ALDS1_11_B Depth First Search
// 2018.5.2 bal4u

#include <stdio.h>
#include <stdlib.h>

#if 1
#define gc() getchar_unlocked()
#else
#define gc() getchar()
#endif

int in()
{
	int n = 0, c = gc();
	do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

#define MAX_V 102
int  d[MAX_V], f[MAX_V];
int  hi[MAX_V], *to[MAX_V];
char mk[MAX_V];
int  tm;

void dfs(int u)
{
	int i, v;

	d[u] = tm++;
	mk[u] = 1;
	for (i = 0; i < hi[u]; i++) {
		v = to[u][i];
		if (!mk[v]) dfs(v);
	}
	f[u] = tm++;
}

int main()
{
	int n, i, j, k, u;

	n = in();
	for (i = 0; i < n; i++) {
		u = in()-1;
		hi[u] = k = in();
		to[u] = malloc(k<<2);
		for (j = 0; j < k; j++) to[u][j] = in()-1;
	}

	tm = 1;
	for (i = 0; i < n; i++) if (mk[i] == 0) dfs(i);
	for (i = 0; i < n; i++) printf("%d %d %d\n", i+1, d[i], f[i]);
	return 0;
}
