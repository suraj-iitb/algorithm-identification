#include<stdio.h>

int bubbleSort(int *A, int N) {
	int i, j;
	int tmp;
	int cnt = 0;

	for (i = 0; i < N - 1; i++) {
		for (j = N - 1; j > i; j--) {
			if (A[j] < A[j - 1]) {
				tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				cnt++;
			}
		}
	}

	return cnt;
}


int main(void) {
	int N;
	int A[100];
	int i;
	int cnt;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	
	cnt = bubbleSort(A, N);
	for (i = 0; i < N; i++) {
	    if(i){
	        printf(" ");
	    }
		printf("%d", A[i]);
	}
	printf("\n%d\n", cnt);

	return 0;
}
