// AOJ ALDS1_11_C Breadth First Search
// 2018.5.2 bal4u

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#define INF 0x10101010
#define MAX_V 102
int  hi[MAX_V], *to[MAX_V];
int  q[MAX_V][2]; int top, end;
int  dist[MAX_V];

void bfs(int u)
{
	int i, v, d;

	q[0][0] = u, q[0][1] = 0, dist[u] = 0, top = 0, end = 1;
	while (top != end) {
		u = q[top][0], d = q[top++][1];
		if (dist[u] < d) continue;
		for (i = 0; i < hi[u]; i++) {
			v = to[u][i];
			if (dist[v] > d+1) {
				dist[v] = d+1, q[end][0] = v, q[end++][1] = d+1;
			}
		}
	}
}

int main()
{
	int n, i, j, k, u;

	n = in();
	memset(dist, INF, n<<2);
	for (i = 0; i < n; i++) {
		u = in()-1;
		hi[u] = k = in();
		to[u] = malloc(k<<2);
		for (j = 0; j < k; j++) to[u][j] = in()-1;
	}

	bfs(0);
	for (i = 0; i < n; i++) {
		if (dist[i] == INF) dist[i] = -1;
		printf("%d %d\n", i+1, dist[i]);
	}
	return 0;
}
