#define MAX 500000
#define SENTINEL 2000000000
#include<stdio.h>
#include<math.h>

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int cnt;

void merge(int A[], int left, int mid, int right) {
	int n1, n2;
	int i, j, k;

	n1 = mid - left;
	n2 = right - mid;

	for (i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}
	for (i = 0; i < n2; i++) {
		R[i] = A[mid + i];
	}
	L[n1] = R[n2] = SENTINEL;

	i = 0;
	j = 0;
	for (k = left; k < right; k++) {
	    cnt++;
		if (L[i] <= R[j]) {
			A[k] = L[i++];
		}
		else {
			A[k] = R[j++];
		}
	}
}

void mergeSort(int A[], int left, int right) {
	int mid;

	if (left + 1 < right) {
		mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main() {
	int n, S[500000], i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &S[i]);
	}

	mergeSort(S, 0, n);
	for (i = 0; i < n; i++) {
		printf("%d", S[i]);
		if (i < n - 1) {
			printf(" ");
		}
	}
	printf("\n");
	printf("%d\n",cnt);
	
	return 0;
}
