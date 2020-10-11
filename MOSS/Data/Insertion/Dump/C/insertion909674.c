#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, *A, i, key, j,p;

	scanf("%d", &n);

	A = (int *)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++){
		scanf("%d", A + i);
	}

	for (p = 0; p < n; p++){
		if (p > 0) printf(" ");
		printf("%d", A[p]);
	}
	printf("\n");

	for (i = 1; i<= (n - 1); i++){
		key = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > key){
			A[j + 1] = A[j];
			j--;
			A[j + 1] = key;
		}

		for (p = 0; p < n; p++){
			if (p > 0) printf(" ");
			printf("%d", A[p]);
		}
		printf("\n");
	}


	return 0;
}
