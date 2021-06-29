#include <stdio.h>

int main(void) {
	int A[100], N, i, j, minj, sw = 0;
	
	scanf("%d", &N);
	
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	
	for(i = 0; i <= N - 1; i++){
		minj = i;
		for(j = i; j <= N - 1; j++){
			if(A[j] < A[minj]){
				minj = j;
			}
		}
		int temp = A[i];
		A[i] = A[minj];
		A[minj] = temp;
		if(i < minj){
			sw++;
		}
	}
	
	for(i = 0; i <= N - 1; i++){
		if(i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
	printf("%d\n", sw);
	
	return 0;
}

