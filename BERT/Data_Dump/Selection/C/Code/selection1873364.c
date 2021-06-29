#include <stdio.h>

int main() {
	int  i, j, b, min, n, cnt, a[100];
	cnt = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (i = 0; i < n; i++) {
		min = i;
		for (j = i; j < n; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		if (i != min) {
			b = a[i];
			a[i] = a[min];
			a[min] = b;
			cnt++;
		}
	}

	for (i = 0; i < n-1; i++) {
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n - 1]);
	printf("%d\n", cnt);

	return 0;
}
