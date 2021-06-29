#include <stdio.h>

int count = 0;

void merge(int a[], int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	int L[n1], R[n2];
	int i, j, k;
	
	for (i = 0; i < n1; i++) {
		L[i] = a[left + i];
	}
	for (i = 0; i < n2; i++) {
		R[i] = a[mid + i];
	}
	L[n1] = 1000000001; //Inf
	R[n2] = 1000000001; //Inf
	i = 0;
	j = 0;
	for (k = left; k < right; k++) {
		count++;
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int a[], int left, int right) {
	int mid;

	if (left + 1 < right) {
		mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid, right);
		merge(a, left, mid, right);
	}
}

int main(void) {
	int a[500000];
	int n, i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	mergeSort(a, 0, n);

	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i != n - 1) {
			putchar(' ');
		}
	}
	putchar('\n');
	printf("%d\n", count);

	return 0;
}
