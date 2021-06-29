#include <stdio.h>
#define SIZE 110

int main(void){
	int i, j, k, temp, A[SIZE], N;
	scanf("%d", &N);

	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}

	for(i = 0; i < N; i++){
		temp = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > temp){
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = temp;

		for(k = 0; k < N - 1; k++){
			printf("%d ", A[k]);
		}
		printf("%d\n", A[N - 1]);
	}
}
