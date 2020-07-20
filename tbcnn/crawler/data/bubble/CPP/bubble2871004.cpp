#include <stdio.h>


int main()
{
	int A[100], N, sw=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &A[i]);
	bool flag = 1;
	for (int i = 0; flag; i++) {
		flag = 0;
		for (int j = N - 1; j >= i + 1; j--) {
			if (A[j] < A[j - 1]) {
				int k = A[j];
				A[j] = A[j - 1];
				A[j- 1] = k;
				flag = 1;
				sw++;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		if (i)printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
	printf("%d\n",sw);
		return 0;
}

