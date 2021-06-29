//1W152348 Yuta MATSUSHIMA
#include <stdio.h>
#define SIZE 110

int main(void){
	int i, j, k, temp, A[SIZE], N;
	int count = 0;
	scanf("%d", &N);

	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}

	for(i = 0; i < N; i++){
		for(j = N - 1; j > i; j--){
			if(A[j - 1] > A[j]){
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				count++;
			}
		}
	}

	for(i = 0; i < N - 1; i++){
		printf("%d ", A[i]);
	}
	printf("%d\n", A[N - 1]);
	printf("%d\n", count);
}
