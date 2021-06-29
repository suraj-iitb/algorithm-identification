#include <stdio.h>

int main(void)
{
	int a[100];
	int i, j, k = 0, tmp;
	int n;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		printf("%d", a[i]);
		if (i == n - 1) {
			printf("\n");
		}
		else {
			printf(" ");
		}
	}

	for (i = 1; i < n; i++) {
		tmp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > tmp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tmp;

		while (k < n) {
			printf("%d", a[k]);
			k++;
			if (k == n) {
				k = 0;
				printf("\n");
				break;
			}
			printf(" ");
		}

		printf("");
	}

	return 0;
}
