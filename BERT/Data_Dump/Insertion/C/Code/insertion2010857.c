#include <stdio.h>

int main(void)
{
	int A[100], i, j, k, N, key;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (i = 0; i < N; i++) {
		key = A[i];
		j = i - 1;
		while (j >= 0&&A[j]>key) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;

		for (k = 0; k < N; k++)
			printf("%d%c", A[k], (k == N - 1) ? '\n' : ' ');
	}

	return 0;
}
