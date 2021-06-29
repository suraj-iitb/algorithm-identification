#include <stdio.h>

void insertionSort(int* a, int n) {
	int i, v, j, k;
	for (i = 1; i <= n; i++) {
		for (k = 0; k < n; k++) {
			printf("%d", a[k]);
			if (k != n - 1) {
				printf(" ");
			} else {
				printf("\n");
			}
		}
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
	}
}

int main(int argc, char const *argv[]) {
	int i, n;
	int a[100];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	insertionSort(a, n);
	return 0;
}
