//AOJ ALDS1_1_A
#include <stdio.h>

int main() {
	int c,d,e,n,o;
	scanf("%d", &n);

	int r[n];
	for (c = 0; c < n; c++) {
		scanf("%d", &r[c]);
	}

	for (c = 0; c < (n - 1); c++) {
		for (e = 0; e < n; e++) {
			if (e != n - 1) {
				printf("%d ", r[e]);
			}else {
				printf("%d\n", r[e]);
			}
		}

		d = c;
		while (r[d] > r[d + 1]) {
			o = r[d + 1];
			r[d + 1] = r[d];
			r[d] = o;
			d--;

		}
	}

	for (e = 0; e < n; e++) {
		if (e != n - 1) {
			printf("%d ", r[e]);
		}else {
			printf("%d\n", r[e]);
		}
	}

	return 0;
}
