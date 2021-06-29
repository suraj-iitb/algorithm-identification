#include <stdio.h>
#define ARRAY_BUFFER_SIZE 100

int main()
{
	int N = 0;

	scanf("%d", &N);

	int A[ARRAY_BUFFER_SIZE] = {0};
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; i++) {
		int value = A[i];
		int j = i;

		while( j >= 1 &&  A[j] < A[j-1] ){
			int tmp = A[j];
			A[j] = A[j-1];
			A[j-1] = tmp;

			--j;
		}
		for (int k = 0; k < N; k++) {
			if (k != N - 1) {
				printf("%d ", A[k]);
			}
			else {
				printf("%d\n", A[k]);
			}
		}

	}

	return 0;
}
