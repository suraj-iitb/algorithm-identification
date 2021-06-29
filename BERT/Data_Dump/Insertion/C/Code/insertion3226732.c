#include <stdio.h>

int main(void) {
	int a[1000], n, v;
	int i, j, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (k = 0; k < n; k++) {
		printf("%d", a[k]);
		if (k != n - 1) {
			putchar(' ');
		}
	}
	putchar('\n');
	for (i = 1; i < n; i++) {
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		for (k = 0; k < n; k++) {
			printf("%d", a[k]);
			if (k != n - 1) {
				putchar(' ');
			}
		}
		putchar('\n');
	}

	return 0;
}

