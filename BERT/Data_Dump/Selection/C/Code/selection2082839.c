#include <stdio.h>

int main() {
	
		int n, i, j, minj, temp, cnt = 0;
		int a[100] = {0};

		scanf("%d", &n);

		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

		for (i = 0; i < n; i++) {
			minj = i;
			for (j = i; j < n; j++) {
				if (a[j] < a[minj]) {
					minj = j;
				}
			}
			if (a[i] > a[minj]) {
				temp = a[i];
				a[i] = a[minj];
				a[minj] = temp;
				cnt++;
			}
		}

		for (i = 0; i < n; i++) {
			if (i == 0) {
				printf("%d", a[i]);
			}
			else {
				printf(" %d", a[i]);
			}
		}
		putchar('\n');
		printf("%d\n", cnt);

	return 0;
}
