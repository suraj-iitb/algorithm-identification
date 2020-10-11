#include <stdio.h>

int main(void) {
	int i, j, rec, count = 0;
	int a[100], n, tmp, min;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n - 1; i++) {
		min = a[i];
		rec = i;
		for (j = i; j < n; j++) {
			//最小検出
			if (min > a[j]) {
				min = a[j];
				rec = j;
			}
		}
		//入れ替え
		if (i != rec) {
			tmp = a[i];
			a[i] = a[rec];
			a[rec] = tmp;
			count++;
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

