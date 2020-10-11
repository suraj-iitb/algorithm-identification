#include <stdio.h>

//????????????.
void swap(int *x, int *y);

int selectionSort(int *a, int n);

int main(void) {
	int i = 0;
	int n = 0;
	int count = 0;
	int a[100] = {};

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	count = selectionSort(a, n);

	for (i = 0; i < n; i++) {
		if (i != n - 1)
			printf("%d ", a[i]);
		else
			printf("%d\n%d\n", a[i], count);
	}

	return 0;
}

void swap(int *x, int *y) {
	int tmp = 0;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int selectionSort(int *a, int n) {
	int i = 0;
	int j = 0;
	int minj = 0;
	
	int count = 0;		//????????????????????°.

	for (i = 0; i < n; i++) {
		minj = i;
		
		for (j = i; j < n; j++) {
			if (a[j] < a[minj])
				minj = j;
		}
		if (minj != i) {
			swap(&a[i], &a[minj]);
			count++;
		}
	}

	return count;
}
