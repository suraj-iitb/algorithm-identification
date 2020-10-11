#include<stdio.h>

#define LIM 500000
#define INF 1000000001

int cnt = 0;
int A[LIM];
int L[LIM], R[LIM];

void merge(int A[], int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	int I, J;
	for (int i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = A[mid + i];
	}
	L[n1] = INF; R[n2] = INF;
	I = 0; J = 0;
	for (int k = left; k < right; k++) {
		if (L[I] <= R[J]) {
			A[k] = L[I];
			I++;
			cnt++;
		}
		else {
			A[k] = R[J];
			J++;
			cnt++;
		}
	}
}

void mergeSort(int A[], int left, int right) {
	if (left + 1 == right)return;
	int mid = (left + right) / 2;
	mergeSort(A, left, mid);
	mergeSort(A, mid, right);
	merge(A, left, mid, right);
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	mergeSort(A, 0, N);

	for (int i = 0; i < N; i++) {
		printf("%d", A[i]);
		if (i != N - 1)printf(" ");
	}
	printf("\n");
	printf("%d\n", cnt);
	return 0;
}
