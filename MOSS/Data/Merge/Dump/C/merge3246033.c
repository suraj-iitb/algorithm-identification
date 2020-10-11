#include <stdio.h>
#include <stdlib.h>

int L[500000], R[500000];
int num = 0;

void merge(int A[], int left, int mid, int right) {
	int i, j, k, n1, n2;
	n1 = mid - left;
	n2 = right - mid;
	
	for (i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}
	for (i = 0; i < n2; i++) {
		R[i] = A[mid + i];
	}

	L[n1] = 1000000000;
	R[n2] = 1000000000;
	i = 0; 
	j = 0;

	for (k = left; k < right; k++) {
		num++;
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i = i + 1;
		}
		else {
			A[k] = R[j];
			j = j + 1;
		}
	}
}

void mergeSort(int A[], int left, int right) {
	int mid;
	
	if ((left + 1) < right) {
		mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main(void)
{
	int n, i;
	int a[550000];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	mergeSort(a, 0, n);

	for (i = 0; i < n; i++) {
		printf("%d", a[i]);

		if (i != (n - 1)) {
			putchar(' ');
		}
		else {
			putchar('\n');
		}
	}

	printf("%d\n", num);

	return 0;	
}

