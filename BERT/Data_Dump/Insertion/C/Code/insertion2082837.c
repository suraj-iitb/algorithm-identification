#include <stdio.h>

int main() {
	
	int n, i, j, k, v;
	int a[100] = {0};

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++) {
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;

		for(k = 0; k < n; k++) {
			if (k == 0) {
				printf("%d", a[k]);
			}
			else {
				printf(" %d", a[k]);
			}
		}
		puts("");
	}

	return 0;
}
