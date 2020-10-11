#include <stdio.h>

int main(void){
	int A[101];
	int N,key,i,j,k;

	scanf("%d", &N);

	for(i = 0;i < N;i++){
		scanf("%d", &A[i]);
	}

	for(k = 0;k < N;k++){
		printf("%d", A[k]);
		if(k != N - 1){
			printf(" ");
		}
	}
	printf("\n");

	for(j = 1;j < N;j++){
		key = A[j];
		i = j - 1;

		while(i >= 0 && A[i] > key){
			A[i+1] = A[i];
			A[i] = key;
			i = i - 1;
		}

		for(k = 0;k < N;k++){
			printf("%d", A[k]);
			if(k != N - 1){
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}
