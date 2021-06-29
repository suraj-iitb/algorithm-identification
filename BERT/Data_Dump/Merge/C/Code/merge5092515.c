#include <stdio.h>

#define N_LIMIT 505000
#define S_LIMIT 1000000000

int count=0;
int A[N_LIMIT],leftarr[N_LIMIT], rightarr[N_LIMIT];

void merge(int *,int,int,int);
void mergesort(int *,int,int);

int main() {
	int i,n;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	mergesort(A,0,n);

	for (i = 0; i < n; i++) {
		printf("%d", A[i]);
		if (i != n - 1)printf(" ");
	}

	printf("\n");
	printf("%d\n", count);

	return 0;
}

void merge(int *A, int left, int mid, int right) {
	int n1 = mid - left,n2 = right - mid;
	int i,k,I,J;
	for (i = 0; i < n1; i++) {
		leftarr[i] = A[left + i];
	}
	for (i = 0; i < n2; i++) {
		rightarr[i] = A[mid + i];
	}
	leftarr[n1] = S_LIMIT; rightarr[n2] = S_LIMIT;

	I = 0; J = 0;
	for (k = left; k < right; k++) {
		if (leftarr[I] <= rightarr[J]) {
			A[k] = leftarr[I];
			I++;
			count++;
		}
		else {
			A[k] = rightarr[J];
			J++;
			count++;
		}
	}
}

void mergesort(int *A, int left, int right) {
	if (left + 1 == right)return;
	int mid = (left + right) / 2;
	mergesort(A, left, mid);
	mergesort(A, mid, right);
	merge(A, left, mid, right);
}

