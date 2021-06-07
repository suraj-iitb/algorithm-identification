#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#define MAX 7777777

#define NF 100
#define INF 1000
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, A[NF][NF], d[NF];
void ax(void) {
  int i, v, head, tail, q[NF*NF], z[NF];

	head = -1;
	tail = 1;
	for (i = 0; i < n; i++) {
		d[i] = INF;
		z[i] = WHITE;
	}
	z[0] = GRAY;
	q[++head] = 0;
	d[0] = 0;

	while (head != tail) {
		v = q[head++];
		for (i = 0; i < n; i++) {
			if (A[v][i] == 1 && z[i] == WHITE) {
				z[i] = GRAY;
				q[tail++] = i;
				d[i] = d[v] + 1;
			}
		}
		z[v] = BLACK;
	}
}
void cl(void) {
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




int main() {
	int i, j, l, m, dt;

	cl();

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
	  
		scanf("%d%d", &l, &m);
		for (j = 0; j < m; j++) {
			scanf("%d", &dt);
			
			A[l - 1][dt - 1] = 1;
		}
	}

	ax();
	print();

	return 0;
}

