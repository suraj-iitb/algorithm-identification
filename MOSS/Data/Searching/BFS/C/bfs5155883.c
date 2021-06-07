#include <stdio.h>
#include <stdlib.h>

void bfs(int);
void enqueue(int);
int dequeue(void);
int** A, n, * d, * color, t = 0, G[100];
int head = 0, tail = 0;
int main() {
	int k, u, v;
	int i, j;

	scanf("%d", &n);
	A = (int**)malloc(sizeof(int*) * (n + 1));
	d = (int*)malloc(sizeof(int) * (n + 1));
	color = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 0; i <= n; i++)  A[i] = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 1; i <= n; i++) {
		color[i] = 0;
		d[i] = -1;
		for (j = 1; j <= n; j++) {
			A[i][j] = 0;
		}
	}

	for (i = 1; i <= n; i++) {
		scanf("%d", &u);
		scanf("%d", &k);
		if (k == 0)continue;
		for (j = 0; j < k; j++) {
			scanf("%d", &v);
			A[u][v] = 1;
		}
	}

	bfs(1);

	for (i = 1; i <= n; i++) {
		printf("%d %d\n", i, d[i]);
	}
	return 0;
}

void bfs(int s) {
	int u, i;
	color[s] = 1;
	d[1] = 0;
	enqueue(s);
	while (1) {
		u = dequeue();
		if (u == NULL)break;
		for (i = 1; i <= n; i++) {
			if (A[u][i] == 1 && color[i] == 0) {
				color[i] = 1;
				d[i] = d[u] + 1;
				enqueue(i);
			}
			color[u] = 2;
		}
	}
}

void enqueue(int key) {
	G[tail] = key;
	if (tail == 99)tail = 0;
	else tail++;
}

int dequeue() {
	int key;
	if (head == tail)return NULL;
	key = G[head];
	if (head == 99)head = 0;
	else head++;
	return key;
}

