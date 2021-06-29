#include<stdio.h>

#define INFTY 150

int G[110][110] = { 0 };
int color[110] = { 0 };

int Distance[110];

int BFSQ[110];
int sp = 0, ep = 1;

void InQ(int p) {
	BFSQ[ep] = p;
	ep = (ep + 1) % 110;
}

int DeQ(void) {
	if (ep - sp == 1)return -1;
	sp = (sp + 1) % 110;
	return BFSQ[sp];

}


int main() {
	int N;
	int k, v;
	int u;
	scanf("%d", &N);
	for (int u = 1; u <= N; u++) {
		scanf("%d", &k);
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &v);
			G[u][v] = 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		Distance[i] = INFTY;
	}
	Distance[1] = 0;
	InQ(1);
	while (1) {
		u = DeQ();
		if (u == -1)break;
		for (int v = 1; v <= N; v++) {
			if (G[u][v] == 1&&color[v]==0) {
				Distance[v] = Distance[u] + 1;
				InQ(v);
				color[v] = 1;
			}
		}
		color[u] = 2;
	}

	for (int i = 1; i <= N; i++) {
		if(Distance[i]!=INFTY)
		printf("%d %d\n", i, Distance[i]);
		else printf("%d -1\n", i);

	}

	return 0;
}
