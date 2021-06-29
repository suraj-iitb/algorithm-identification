#include <stdio.h>
#include <limits.h>
const int N = 500000;
const int INFTY = INT_MAX;
int cunt = 0;
void merge(int*, int, int, int);
void mergeSort(int*, int, int);
int main() {
	int i,S[N],n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &S[i]);
	}
	mergeSort(S, 0, n);
	for (i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%d", S[i]);
	}
	printf("\n");
	printf("%d\n",cunt);
	return 0;
}
void merge(int *A, int left, int mid, int right) {
	int n1, n2, i, j, k,R[N],L[N];
	n1 = mid - left;
	n2 = right - mid;
	//L[0...n1], R[0...n2] を生成
	for (i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}
	for (i = 0; i < n2; i++) {
		R[i] = A[mid + i];
	}

	L[n1] = INFTY;
	R[n2] = INFTY;
	i = 0;
	j = 0;
	for (k = left; k < right; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i = i + 1;
		}
		else {
			A[k] = R[j];
			j = j + 1;
		}
		/*
		for (a = 0; a < n; a++) {
			if (a) printf(" ");
			printf("A[%d] %d",a, A[a]);

		}
		printf("\n");
		*/
		cunt++;
	}
}

void mergeSort(int *A, int left, int right) {
	int mid, i;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}
