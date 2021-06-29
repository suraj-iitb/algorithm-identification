#include<stdio.h>
#include<string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 10000

#define N 100
#define INF 1000
#define WHITE 0

#define GRAY 1

#define BLACK 2


void cal(void);
void print(void);
void bfs(void);
int n, A[N][N], d[N];

int main() {
	int i, j, l, m, data;

	cal();

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
	  
		scanf("%d%d", &l, &m);
		for (j = 0; j < m; j++) {
			scanf("%d", &data);
			
			A[l - 1][data - 1] = 1;
		}
	}

	bfs();
	print();

	return 0;
}
void bfs(void) {
	int i, v;
	int head, tail, que[N*N], z[N];

	head = -1;
	tail = 1;
	for (i = 0; i < n; i++) {
		d[i] = INF;
		z[i] = WHITE;
	}
	z[0] = GRAY;
	que[++head] = 0;
	d[0] = 0;

	while (head != tail) {
		v = que[head++];
		for (i = 0; i < n; i++) {
			if (A[v][i] == 1 && z[i] == WHITE) {
				z[i] = GRAY;
				que[tail++] = i;
				d[i] = d[v] + 1;
			}
		}
		z[v] = BLACK;
	}
}
void cal(void) {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = 0;
		}
	}
	return ;
}
void print(void) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", i + 1);
		if (d[i] == INF) printf("-1\n");
		else			 printf("%d\n", d[i]);
	}
	return ;
}

