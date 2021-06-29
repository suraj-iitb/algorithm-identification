#include <stdio.h>
#include <stdlib.h>
void counting_sort(int *in, int *out, int n) {
	int i, c[10001] = {0};

	for (i = 0; i < n; i++) {
		c[in[i]] += 1;
	}
	for (i = 1; i < 10001; i++) {
		c[i] += c[i-1];
	}
	for (i = n-1; i >= 0; i--) {
		out[c[in[i]]] = in[i];
		c[in[i]] -= 1;
	}
}

int main(void) {
	int n, *in, *out, i;
	const char *fmt = "%d";

	scanf("%d", &n);

	in = malloc(sizeof(int)*n);
	out = malloc(sizeof(int)*(n+1));
	for (i = 0; i < n; i++) {
		scanf("%d", in+i);
	}
	counting_sort(in, out, n);
	for (i = 1; i < n+1; i++) {
		printf(fmt, out[i]);
		fmt = " %d";
	}
	putchar('\n');
	return 0;
}
