#include <stdio.h>

constexpr int kInf = int(2E9 + 10), kN = int(1E2 + 10);

int min(int a, int b) {return a > b ? b : a;}

int dis[kN][kN];

void out(int n) {n == kInf ? printf("INF") : printf("%d", n);}

int main () {
	int n, m, l, r, c;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dis[i][j] = kInf;
	for (int i = 0; i < n; i++) dis[i][i] = 0;
	while (m--) {
		scanf("%d%d%d", &l, &r, &c);
		dis[l][r] = c;
	}
	for (int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if (dis[i][k] != kInf && dis[k][j] != kInf) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 0; i < n; i++) if (dis[i][i] < 0) {
		printf("NEGATIVE CYCLE\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		out(dis[i][0]);
		for (int j = 1; j < n; j++) {
			printf(" ");
			out(dis[i][j]);
		}
		printf("\n");
	}
}

