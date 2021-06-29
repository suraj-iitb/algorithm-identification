#include <stdio.h>
#include <stdlib.h>

static int cnt = 0;
int *a, temp, n;

void trace(int a[], int n) {
	int i;

	for (i = 1; i <= n; i++) {
		if (i > 1) {
			printf(" ");
		}
		printf("%d", a[i]);
	}
	printf("\n%d\n", cnt);

}

void swap(int *x, int *y) {
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
	cnt++;
}

void SelectionSort(void) {
	int i, j, mini;

	for (i = 1; i < n; i++) {
		mini = i;
		for (j = i; j <= n; j++) {
			if (a[j] < a[mini]) {
				mini = j;
			}
		}
		if (a[i] > a[mini]) {
			swap(&a[i], &a[mini]);
		}
	}

}

int main(void) {
	int i;

	scanf("%d", &n);
	a = (int *) malloc(sizeof(int) * (n + 1));

	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	SelectionSort();

	trace(a, n);

	return 0;
}
