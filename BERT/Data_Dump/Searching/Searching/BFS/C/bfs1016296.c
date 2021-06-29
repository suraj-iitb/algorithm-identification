#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY -1
#define BLACK 1
#define INF -1
#define MAX 100

int *u, *k, **v, *color, *d;
int *queue, head, tail;
int n, time;

void init() {
	int i, j;

	u = (int *)malloc(sizeof(int) * (n + 1));
	k = (int *)malloc(sizeof(int) * (n + 1));
	color = (int *)malloc(sizeof(int) * (n + 1));
	d = (int *)malloc(sizeof(int) * (n + 1));
	v = (int **)malloc(sizeof(int *) * (n + 1));
	queue = (int *)malloc(sizeof(int) * (n + 1));
}

void input() {
	int i, j;

	scanf("%d", &n);
	init();

	for (i = 1; i <= n; i++) {
		scanf("%d%d", &u[i], &k[i]);
		v[i] = (int *)malloc(sizeof(int) * (k[i] + 1));
		for (j = 1; j <= k[i]; j++) {
			scanf("%d", &v[i][j]);
		}
	}
}

void enqueue(int q) {
	if (tail > MAX) tail = 0;
	queue[tail++] = q;
}

int dequeue() {
	int x = queue[head];

	if (head == tail || head > tail) return x;
	else {
		if (head > MAX) {
			head = 0;
		}
	}
	return queue[head++];
}

void BFS(int s) {
	int i, u;

	for (i = 1; i <= n; i++) {
		color[i] = WHITE;
		d[i] = INF;
	}
	color[s] = GRAY;
	d[s] = 0;
	enqueue(s);

	while (head != tail) {
		u = dequeue();
		for (i = 1; i <= k[u]; i++) {
			if (color[v[u][i]] == WHITE) {
				color[v[u][i]] = GRAY;
				d[v[u][i]] = d[u] + 1;
				enqueue(v[u][i]);
			}
		}
		color[u] = BLACK;
	}
}

void output() {
	int i;

	for (i = 1; i <= n; i++) {
		printf("%d %d\n", u[i], d[i]);
		free(v[i]);
	}
	free(u);
	free(k);
	free(v);
	free(color);
	free(queue);
}

main () {
	input();
	BFS(u[1]);
	output();
	return 0;
}
