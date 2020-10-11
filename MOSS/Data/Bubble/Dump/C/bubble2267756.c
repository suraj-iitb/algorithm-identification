#include <stdio.h>

#define N 100

int bubbleSort(int *A, int n) {
	int i, tmp;
	int flag = 1;
	int count = 0;

	while (flag) {
		flag = 0;
		for (i = n-1; i > 0; i--) {
			if (A[i] < A[i-1]) {
				tmp = A[i];
				A[i] = A[i-1];
				A[i-1] = tmp;

				count++;
				flag = 1;
			}
		}
	}

	return count;
}

int main (){
	int i,n;
	int A[N];
	int count;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	count = bubbleSort(A, n);

	for (i = 0; i < n-1; i++)
		printf("%d ", A[i]);

	printf("%d\n", A[i]);
	printf("%d\n", count);

	return 0;
}
