#include <stdio.h>

int main () {
	int c,d,n,m,count;
	scanf("%d", &n);

	int a[n];
	for (c = 0; c < n; c++) {
		scanf("%d", &a[c]);
	}

	count = 0;
	for (c = 0; c < (n - 1); c++) {
		if (a[c] > a[c + 1]) {
			d = c;
			while (a[d] > a[d + 1]) {
				m = a[d];
				a[d] = a[d + 1];
				a[d + 1] = m;
				if (d != 0) {
					d--;
				}
				count++;
			}
		}
	}

	for (c = 0; c < n; c++) {
		if (c == (n - 1)) {
			printf("%d\n", a[c]);
		}else {
			printf("%d ", a[c]);
		}
	}

	printf("%d\n", count);

	return 0;
}
