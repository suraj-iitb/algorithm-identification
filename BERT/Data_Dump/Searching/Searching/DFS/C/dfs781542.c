#include <stdio.h>

int walk(int index, int time, int wayto[101][101], int *d, int *f) {
	int *p;

	d[index] = ++time;
	for (p = wayto[index]; *p != 0; p++) {
		if (!d[*p]) {
			time = walk(*p, time, wayto, d, f);
		}
	}
	f[index] = ++time;
	return time;
}

int main(void) {
	int num, i, j, u, k, tm = 0;
	int d[101] = {0}, f[101] = {0};
	int wayto[101][101] = {{0}};

	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d %d", &u, &k);
		for (j = 0; j < k; j++) {
			scanf("%d", &wayto[u][j]);
		}
	}

	for (i = 1; i <= num; i++) {
		if (!d[i]) {
			tm = walk(i, tm, wayto, d, f);
		}
	}

	for (i = 1; i <= num; i++) {
		printf("%d %d %d\n", i, d[i], f[i]);
	}
	return 0;
}
