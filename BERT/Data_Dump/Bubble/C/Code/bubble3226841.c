#include <stdio.h>

int main(void)
{
	int flag, count = 0;
	int i, n, tmp;
	int a[100];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	flag = 1;

	while (flag) {
		flag = 0;
		for (i = n - 1; i > 0; i--) {
			if (a[i] < a[i - 1]) {
				tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				flag = 1;
				count++;
			}
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
