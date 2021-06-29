#include "stdio.h"

int main()
{
	int N,v,j;
	int A[100];
	scanf("%d",&N);
	for (int i=0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 1; i < N; i++) {
		for (int k = 0; k < N - 1; k++)printf("%d ", A[k]);
		printf("%d\n", A[N - 1]);
		v = A[i];
		j = i - 1;
		while (j >= 0 and A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		
	}

	for (int k = 0; k < N - 1; k++)printf("%d ", A[k]);
	printf("%d\n", A[N - 1]);

	
	
	return 0;
}
