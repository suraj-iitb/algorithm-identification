#include <stdio.h>

void trace(int *A, int n){
	for(int i = 0; i < n; i++){
		if(i > 0) printf(" ");
		printf("%d", A[i]);
	}

	printf("\n");
}

int main(){
	int i, j, n, A[100];

	scanf("%d", &n);

	for(i = 0; i < n; i++)
		scanf("%d", A + i);

	// Selection Sort
	int count = 0;
	int minj;
	int t;

	for(i = 0; i < n; i++){
		minj = i;

		for(j = i+1; j < n; j++){
			if(A[j] < A[minj]){
				minj = j;
			}
		}

		if(minj != i){
			t = A[i];
			A[i] = A[minj];
			A[minj] = t;
			count++;
		}
	}

	trace(A, n);
	printf("%d\n", count);

	return 0;
}

