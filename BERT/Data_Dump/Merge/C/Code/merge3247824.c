/* ADLS1_5_B:Merge Sort */
/* 20181119 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 500000

int cnt;
int L[N / 2 + 1], R[N / 2 + 1];

void mergeSort(int *A, int n, int left, int right);
void merge(int *A, int left, int mid, int right);

int main(void) {
	int n, i;
	//int *A = (int *)malloc(sizeof(int) * N);
	int A[N];

	cnt = 0;

	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}

	mergeSort(A, n, 0, n);
	
	i = 0;
	while(i < n) {
		if(i) printf(" ");
		printf("%d", A[i++]);
	}
	printf("\n%d\n", cnt);

	return 0;
}

void mergeSort(int *A, int n, int left, int right) {
	int mid;

	if(left + 1 < right) {
		mid = (left + right) / 2;
		mergeSort(A, n, left, mid);
		mergeSort(A, n, mid, right);
		merge(A, left, mid, right);
	}
}

void merge(int *A, int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	int i, j, k;

	i = j = 0;
	while(i < n1) {
		L[i] = A[left + i];
		i++;
	}
	while(j < n2) {
		R[j] = A[mid + j];
		j++;
	}

	i = j = 0;
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	for(k = left; k < right; k++) {
		if(L[i] <= R[j]) {
			A[k] = L[i++];
		}else {
			A[k] = R[j++];
		}
		cnt++;
	}
}
