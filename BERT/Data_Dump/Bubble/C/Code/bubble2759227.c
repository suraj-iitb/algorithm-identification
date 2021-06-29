#include<stdio.h>

int bubbleSort(int *A, int N)
{
	int flag, i, j, t, count = 0;

	flag = 1;
	while (flag) {
		flag = 0;
		for (j = N - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				t = A[j];
				A[j] = A[j - 1];
				A[j - 1] = t;
				count++;
				flag = 1;
			}
		}
	}

	return count;
}

int main(void)
{
	int N, A[100], i, c;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	c = bubbleSort(A, N);
	printf("%d", A[0]);
	for (i = 1; i < N; i++) {
		printf(" %d", A[i]);
	}
	printf("\n%d\n", c);

	return 0;
}

