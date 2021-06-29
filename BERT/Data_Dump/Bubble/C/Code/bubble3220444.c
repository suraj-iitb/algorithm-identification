#include <stdio.h>

void trace(int *A, int n){
	for(int i = 0; i < n; i++){
		if(i > 0) printf(" ");
		printf("%d", A[i]);
	}

	printf("\n");
}

int main(){
	int i, j, t, n, A[100];

	scanf("%d", &n);

	for(i = 0; i < n; i++)
		scanf("%d", A + i);

	int flag = 1;
	int count = 0;
	i = 0;

	while(flag){
		flag = 0;

		for(j = n - 1; j > i; j--){
			if(A[j] < A[j-1]){
				t = A[j];
				A[j] = A[j-1];
				A[j-1] = t;
				flag = 1;
				count++;
			}
		}

		i++;
	}

	trace(A, n);
	printf("%d\n", count);

	return 0;
}

