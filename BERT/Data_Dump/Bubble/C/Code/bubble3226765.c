#include <stdio.h>

int main(void) {
	int i, j, count = 0;
	int a[100], n, tmp;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
				count++;
			}
		}
	}

	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i != n - 1) {
			putchar(' ');
		}
	}
	putchar('\n');

	printf("%d\n", count);

	return 0;
}

