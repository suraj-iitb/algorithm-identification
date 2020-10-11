#include <stdio.h>

#define N   101

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int Selection_Sort(int a[], int num) {
	int i, j, mini, counter = 0;
	for (i = 1; i <= num; i++) {
		mini = i;
		for (j = i; j <= num; j++) {
			if (a[j] < a[mini]) {
				mini = j;
			}
		}
		if (i != mini) {
		swap(&a[i], &a[mini]);
		counter++;
		}
	}
	return counter;
}

int main(void) {
	int i, n, count;
	int A[N];
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}

	count = Selection_Sort(A, n);

	for (i = 1; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("%d\n%d\n", A[n], count);

	return 0;
}
