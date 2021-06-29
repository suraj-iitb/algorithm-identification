#include<stdio.h>

void print(int* A, int N) {
	int i;
	for (i = 0; i < N; i++) {
		if (i) 
		printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}

int bubble_sort(int* A, int N) {
	int i, j;
	int cnt = 0;
	for (i = 0; i < N; i++)
		for (j = N - 1; j >= i + 1; j--)
			if (A[j] < A[j - 1]) {
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				cnt++;
			}
	print(A, N);
	return cnt;
}

int main() {
	int i, N;
	int data[100];
	scanf("%d", &N);
	
	for (i = 0; i < N; i++) 
	scanf("%d", &data[i]);
	printf("%d\n", bubble_sort(data, N));

	return 0;
}


