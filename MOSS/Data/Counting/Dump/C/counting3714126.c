#include <stdio.h>
#include <string.h>

#define MAX_NO 2000000
#define MAX_VALUE 10000

int A[MAX_NO + 5];
int B[MAX_NO + 5];
int C[MAX_VALUE + 5] = { 0 };
int n, k = 0;

void CountingSort();

int main()
{
	int i;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		if (A[i] > k) k = A[i];
	}
	CountingSort(n);
	for (i = 1; i <= n - 1; i++) printf("%d ", B[i]);
	printf("%d\n", B[i]);
}

void CountingSort() {
	int i;
	for (i = 1; i <= n; i++) C[A[i]]++;

	for (i = 1; i <= k; i++) C[i] += C[i - 1];

	for (i = n; i >= 1; i--) {
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
}


