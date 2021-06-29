#include <stdio.h>
int main(void) {
	int flag = 1, i, j, minj, n, swap, changes = 0, a[100];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n; i++) {
		minj = i;
		for (j = i; j < n; j++) {
			if (a[j] < a[minj])
				minj = j;
		}
		if (a[i] != a[minj]) {
			swap = a[i];
			a[i] = a[minj];
			a[minj] = swap;
			changes++;
		}
	}
	for (j = 0; j < n - 1; j++)
		printf("%d ", a[j]);
	printf("%d\n", a[n - 1]);
	printf("%d\n", changes);
	return 0;
}
