# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define S_MAX 500000
#define INFTY 1000000000

void merge(int A[], int left, int mid, int right);
void mergeSort(int A[], int left, int right);

int merge_cnt = 0;

int main(void) {

	int n;
	int i;
	int s[S_MAX + 1];

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	mergeSort(s, 0, n);
	
	for (i = 0; i < n; i++) {
		printf("%d",s[i]);
		if (i != n - 1) {
			printf(" ");
		}
	}
	printf("\n%d\n", merge_cnt);
	return 0;
}

void merge(int A[], int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	int i, j, k;

	int L[S_MAX];
	int R[S_MAX];

	//L[0...n1], R[0...n2] ?????????
	for (i = 0; i <= n1 - 1; i++) {
		L[i] = A[left + i];
	}
	for (i = 0; i <= n2 - 1; i++) {
		R[i] = A[mid + i];
	}
	L[n1] = INFTY;
	R[n2] = INFTY;
	i = 0;
	j = 0;
	for (k = left; k <= right - 1; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i = i + 1;
		}
		else {
			A[k] = R[j];
			j = j + 1;
		}
		merge_cnt++;
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
