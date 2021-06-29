#include<stdio.h>
#define BIG 2000000000
#define MAX 500000

int c = 0;

void merge(int a[], int left, int mid, int right) {
	int i, k, j;
	int n1 = mid - left, n2 = right - mid;
	int L[MAX/2 + 2], R[MAX/2 + 2];

	for (i = 0; i < n1; ++i) {
		L[i] = a[left + i];
	}

	for (i = 0; i < n2; ++i) {
		R[i] = a[mid + i];
	}

	L[n1] = BIG;
	R[n2] = BIG;
	i = 0;
	j = 0;

	for (k = left; k < right; ++k) {
		c = c + 1;
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i = i + 1;
		}
		else {
			a[k] = R[j];
			j = j + 1;
		}
	}
}

void mergeSort(int a[], int left, int right) {

	int mid;

	if (left + 1 < right) {
		mid = (left + right)/2;
		mergeSort(a, left, mid);
		mergeSort(a, mid, right);
		merge(a, left, mid, right);
	}

}

int main() {
	int n, a[MAX], i;

	scanf("%d", &n);

	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	mergeSort(a, 0, n);

	for (i = 0; i < n; ++i) {
		printf("%d", a[i]);
		if (i == n - 1) {
			printf("\n");
		}
		else {
			printf(" ");
		}
	}

	printf("%d\n", c);
	return 0;
}
