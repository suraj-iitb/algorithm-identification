#include <stdio.h>

void print(int A[], int N) {
	int i;
	for (i = 0; i < N; i++) {
		printf("%d",A[i]);
		if(i < N -1) {
			printf(" ");
		}
	}
	printf("\n");
}
int main(void) {
	int N, A[100], v;
	int i, j;
	scanf("%d",&N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	print(A, N);
	for (i = 1; i < N; i++) {
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		print(A, N);
	}
	return 0;
}
