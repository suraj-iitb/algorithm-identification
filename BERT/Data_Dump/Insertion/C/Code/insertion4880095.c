#include <stdio.h>

int main() {

	int a[1010];
	int n, i, j, k, key;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n - 1; i++) {
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n - 1]);

	for (i = 1; i <= n - 1; i++) {
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
			a[j + 1] = key;
		}
		for (k = 0; k < n - 1; k++) {
			printf("%d ", a[k]);
		}
		printf("%d\n", a[n - 1]);
	}
	return 0;
}
