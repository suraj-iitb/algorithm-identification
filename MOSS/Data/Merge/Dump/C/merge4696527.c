#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define sentinel INT_MAX

int count = 0;


void merge(int A[], int left, int right, int mid) {
	int n1 = mid - left;
	int n2 = right - mid;
	//make 2 arrays Left and Right
int L[n1],R[n2];
int i,j,k;
i=0;
j=0;
k=left;

	for (int i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}

	for (int i = 0; i < n2; i++) {
		R[i] = A[mid + i];
	}

	L[n1] = sentinel;
	R[n2] = sentinel;


	for (k = left; k < right; k++) {
		count++;
		if (L[i] <= R[j]) {
			A[k] = L[i];
            i++;
		}
		else {
			A[k] = R[j];
            j++;
		}
	}

}

void merge_sort(int A[], int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		merge_sort(A, left, mid);
		merge_sort(A, mid, right);
		merge(A, left, right, mid);
	}
}

int main() {
	int size;
    int i;
	scanf("%d", &size);

	int A[1000000];
	
	for (i = 0; i != size; i++) {
		scanf("%d", &A[i]);
	}

	merge_sort(A, 0, size);

	for (int i = 0; i < size - 1; i++) {
		printf("%d ", A[i]);
	}
	printf("%d\n%d\n", A[size - 1],count);
	return 0;
}


