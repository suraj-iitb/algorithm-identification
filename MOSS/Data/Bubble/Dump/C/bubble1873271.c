#include <stdio.h>

int main() {
	int b, i, n, flag, cnt, a[100];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	flag = 1;
	cnt = 0;

	while (flag == 1) {
		flag = 0;

		for (i = n - 1; i > 0; i--) {
			if (a[i - 1] > a[i]) {
				b = a[i];
				a[i] = a[i - 1];
				a[i - 1] = b;
				cnt++;
				flag = 1;
			}
		}
	}

	for (i = 0; i < n-1; i++) {
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n - 1]);
	printf("%d\n", cnt);

	return 0;
}
