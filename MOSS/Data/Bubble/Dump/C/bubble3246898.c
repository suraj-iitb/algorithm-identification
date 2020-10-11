#include <stdio.h>

int main(void){
	int i, j, k, n, flag, counter = 0;
	int A[100];
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}
	flag = 1;
	while(flag){
		flag = 0;
		for(j = n-1; j >= 1; j--){
			if(A[j] < A[j-1]){
				int temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;
				flag = 1;
				counter++;
			}
		}
	}

	printf("%d", A[0]);
	for(k = 1; k < n; k++){
		printf(" %d", A[k]);
	}
	printf("\n");
	printf("%d\n", counter);
	return 0;
}
