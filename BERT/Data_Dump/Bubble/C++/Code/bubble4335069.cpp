#include <stdio.h>
int bubbleSort(int A[], int N) {
	int flag = 1, count = 0;
	while (flag)
	{
		flag = 0;
		for (int j = N - 1; j > 0; j--)
		{
			if (A[j] < A[j - 1]) {
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				flag = 1;
				count++;
			}
		}
	}

	for (int k = 0; k < N; k++)
	{
		if (k > 0) printf(" ");
		printf("%d", A[k]);
	}
	printf("\n%d\n", count);

	return 0;
}


int main() {
	int N, i, j;
	int A[100];

	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &A[i]);

	bubbleSort(A, N);

	return 0;
}
