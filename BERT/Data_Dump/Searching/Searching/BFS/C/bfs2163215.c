#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX 101

int n, M[MAX][MAX] = {0}, d[MAX] = {0};
int color[MAX] = {WHITE};

int head = 0;
int tail = 0;
int Q[MAX] = {0};

void initialise() {
	head = tail = 0;
}

int isEmpty() {
	return head == tail;
}

int isFull() {
	return head == (tail + 1) % MAX;
}

void enqueue(int x) {
	if (isFull()) {
		printf("Over flow\n");
		exit(0);
	}
	
	Q[tail] = x;
	if (tail + 1 == MAX) {
		tail = 0;
	} else {
		tail++;
	}
	return;
}

int dequeue() {
	int x;
	if (isEmpty()) {
		printf("Under flow\n");
		exit(0);
	}
	x = Q[head];
	if (head + 1 == MAX) {
		head = 0;
	} else {
		head++;
	}
	return x;
}




void bfs(int x) {
	int i, u, v;

	for (i = 0; i < n; ++i) {
		d[i] = -1;
		//printf("%d %d\n", i+1, d[i]);
	}
	
	initialise();
	color[x] = GRAY;
	d[x] = 0;
	enqueue(x);

//	printf("x = %d\n", x);
	while (!isEmpty()) {
		u = dequeue();
//		printf("u = %d\n", u);
		for (v = 0; v < n; ++v) {
			if (M[u][v] && color[v] == WHITE) {
//				printf("u = %d, v = %d\n", u, v);
				color[v] = GRAY;
				d[v] = d[u] + 1;
				enqueue(v);
			}
		}
		color[u] = BLACK;
	}

	for (i = 0; i < n; ++i) {
		printf("%d %d\n", i+1, d[i]);
	}
}

int main() {
	int i, j, u, k, v;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d", &u, &k);
		u--;
		for (j = 0; j < k; ++j) {
			scanf("%d", &v);
			v--;
			M[u][v] = 1;
		}
	}

	bfs(0);
	
	return 0;
}
