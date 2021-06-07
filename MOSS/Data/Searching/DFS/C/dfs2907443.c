#include<stdio.h>

int G[110][110] = { 0 };
int color[110] = { 0 };

int DFStack[110];
int sp = 0;

int ans[110][2] = { 0 };

void Push(int p) {
	DFStack[sp] = p;
	sp++;
}

int Pop(void) {
	if (sp == 0)return -1;
	sp--;
	return DFStack[sp];
}


int main() {
	int N;
	int k, v;
	int pos, search_point;
	int cnt = 1;
	int fin = 0;
	scanf("%d", &N);
	for (int u = 1; u <= N; u++) {
		scanf("%d", &k);
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &v);
			G[u][v] = 1;
		}
	}
	while (1) {
		for (int i = 1; i <= N; i++) {
			if (ans[i][0] == 0) {
				Push(i); break;
			}
			else if (i == N)fin = 1;
		}
		while (sp != 0) {
			pos = Pop();
			if (color[pos] == 0) {
				color[pos] = 1;
				ans[pos][0] = cnt;
				cnt++;
			}
			search_point = 1;
			while ((G[pos][search_point] == 0 || color[search_point] != 0) && search_point <= N)search_point++;
			if (search_point == N + 1) {
				color[pos] = 2;
				ans[pos][1] = cnt;
				cnt++;
			}
			else {
				Push(pos);
				Push(search_point);
			}
		}
		if (fin)break;
	}

	for (int i = 1; i <= N; i++) {
		printf("%d %d %d\n", i, ans[i][0], ans[i][1]);
	}

	return 0;
}
