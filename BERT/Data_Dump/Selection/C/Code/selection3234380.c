#include <stdio.h>

int main(void)
{
	int a[100];
	int n, i, j, tmp;
	int minj, count = 0;

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
		if (i != minj) {
			tmp = a[i];
			a[i] = a[minj];
			a[minj] = tmp;
			count++;
		}
	}


	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i == n - 1) {
			printf("\n");
		}
		else {
			printf(" ");
		}
	}
	printf("%d\n", count);

	return 0;
}
