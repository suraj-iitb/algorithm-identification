#include <stdio.h>
#include <stdlib.h>

#define N 101
#define INF -1

int Q[N];
int head,tail;
int M[N][N] = {{}};
int d[N];
int n;
char color[N];

void enqueue(int key) {
	Q[tail] = key;
	if (tail == N-1) {
		tail = 0;
	}
	else {
		tail++;
	}
}

int dequeue() {
	int x;
	x = Q[head];
	if (head == N-1) {
		head = 0;
	}
	else {
		head++;
	}
	return x;
}

void bfs (int s) {
	int i,u;
	for(i=1;i<=n;i++) {
		d[i] = INF;
		color[i] = 'W';
	}

	color[s] = 'G';
	d[s] = 0;
	enqueue(s);
	while(head != tail) {
		u = dequeue();
		for (i=1;i<=n;i++) {
			if (M[u][i] == 1 && color[i] == 'W') {
			color[i] = 'G';
			d[i] = d[u] + 1;
			enqueue(i);
			}
		}
	color[u] = 'B';
	}
}

int main() {
	int i,j;
	int u,k,v;

	scanf("%d", &n);
	for (i=1;i<=n;i++) {
		scanf("%d%d",&u,&k);
		for (j=1;j<=k;j++) {
			scanf("%d",&v);
			M[u][v] = 1;
		}
	}

	bfs(1);

	for (i=1;i<=n;i++) {
		printf("%d %d\n",i,d[i]);
	}
	return 0;
}
