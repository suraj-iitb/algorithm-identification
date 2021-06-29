#include <stdio.h>
#include <string.h>

int main() {
	int n;
	int a[101] = { 0 };
	int i, j, v, k;

	scanf("%d", &n);

	for (i = 0; i < n ;i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++) {
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
			a[j + 1] = v;
		}
		for (k = 0; k < n; k++) {
			printf("%d", a[k]);
			if (k < n - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}


	return 0;
}
