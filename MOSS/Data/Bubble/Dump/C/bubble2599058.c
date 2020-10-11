#include <stdio.h>

int main()
{
	int N, i, j, k, count = 0;
	int A[100];
	
	scanf("%d",&N);
	for(i = 0; i < N; i++) scanf("%d",&A[i]);
	
	for(j = 0; j < N-1; j++){
		for(i = N-1; i > 0; i--){
			if(A[i] < A[i-1]){
				k = A[i];
				A[i] = A[i-1];
				A[i-1] = k;
				count++;
			}
		}
	}

	
	for(i = 0; i < N; i++){
		if(i > 0) printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
	printf("%d\n",count);
	
	return 0;
}
