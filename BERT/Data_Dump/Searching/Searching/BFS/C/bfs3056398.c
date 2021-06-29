#include <stdbool.h>
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

typedef int data_t;
data_t queue[MAX_N];
int head, tail;

void enqueue(data_t data) {
	queue[tail++] = data;
}

data_t dequeue() {
	return queue[head++];
}

bool empty() {
	return head == tail;
}

int dist[MAX_N];

void bfs(int s) {
	edge *e;

	memset(dist, -1, sizeof(dist));
	dist[s] = 0;
	enqueue(s);

	while(!empty()) {
		const int u = dequeue();
		for(e = adj[u]; e != NULL; e = e->next) {
			if(dist[e->to] == -1) {
				dist[e->to] = dist[u] + 1;
				enqueue(e->to);
			}
		}
	}
}

int main() {
	int n;
	int u, k;
	int i, j;
	int v;

	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d %d", &u, &k);
		for(j = 0; j < k; ++j) {
			scanf("%d", &v);
			add_edge(u - 1, v - 1);
		}
	}

	bfs(0);
	for(u = 0; u < n; ++u) {
		printf("%d %d\n", u + 1, dist[u]);
	}

	return EXIT_SUCCESS;
}

