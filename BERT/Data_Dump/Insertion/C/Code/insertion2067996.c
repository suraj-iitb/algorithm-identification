#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
void insertionSort(int A[], int N);
int main() {
	int A[100] = { 0 }, n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &A[i]);
	insertionSort(A, n);
	return 0;
}

void insertionSort(int A[], int N)
{
	int i, j, v, k;
	for (k = 0; k < N; k++) printf("%d%c", A[k], k < N - 1 ? ' ' : '\n');
	for (i = 1; i <= N - 1; i++) {
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		for (k = 0; k < N; k++) printf("%d%c", A[k], k < N-1 ? ' ' : '\n');
	}
}
