#include <stdio.h>

#define BLACK 0
#define GRAY 1
#define WHITE 2
#define N_MAX 101
#define INF 9999999

int A[N_MAX][N_MAX];
int color[N_MAX], d[N_MAX];
int Queue[1000];
int start, end;
int n;

void BFS(int);
void init();

int main() {
	int i, j, k, num, to;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d", &num, &k);
		for (j = 0; j < k; j++) {
			scanf("%d", &to);
			A[num - 1][to - 1] = 1;
		}
	}

	BFS(0);
	for (i = 0; i < n; i++) {
		printf("%d %d\n", i + 1, d[i]);
	}
	return 0;
}

void init() {
	int i;
	for (i = 0; i < N_MAX; i++) {
		color[i] = WHITE;
		d[i] = INF;
	}
	start = end = 0;
}

void BFS(int a) {
	int b, c;
	int i, j;
	init();
	color[a] = GRAY;
	d[a] = 0;
	Queue[end] = a;
	end++;
	while (start != end) {
		b = Queue[start];
		start++;
		for (c = 0; c < n; c++) {
			if (color[c] == WHITE) {
				if (A[b][c] == 1) {
					color[c] = GRAY;
					d[c] = d[b] + 1;
					Queue[end] = c;
					end++;
				}
			}
			color[b] = BLACK;
		}
	}
	for (i = 0; i < N_MAX; i++) {
		if (d[i] == INF) d[i] = -1;
	}
}
