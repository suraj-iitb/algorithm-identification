#include <stdio.h>

int main(void){
	int i, j, k, n, v;
	int A[1000];
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}
	printf("%d", A[0]);
	for(k = 1; k < n; k++){
		printf(" %d", A[k]);
	}
	printf("\n");
	for(i = 1; i <= n-1; i++){
		v = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > v){
			A[j+1] = A[j];
			j--;
			A[j+1] = v;
		}
		printf("%d", A[0]);
		for(k = 1; k < n; k++){
			printf(" %d", A[k]);
		}
		printf("\n");
	}
	return 0;
}
