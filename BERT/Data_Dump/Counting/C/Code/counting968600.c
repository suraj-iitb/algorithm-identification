#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Counting_Sort(int *A, int *B, int k, int length){
	int i, j, C[100000];
	for (i = 0; i <= k; i++){
		C[i] = 0;
	}
	for (j = 1; j <= length; j++){
		C[A[j]]++;
	}
	/* C[i]にはiの出現数が記録されている*/
	for (i = 1; i <= k; i++){
		C[i] = C[i] + C[i - 1];
	}
	/* C[i]にはi以下の数の出現数が記録されている*/
	for (j = length; j >= 1; j--){
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
}

int main(){
	int n, i, *A, *B, max = -1;
	scanf("%d", &n);
	A = (int *)malloc(sizeof(int)*n);
	B = (int *)malloc(sizeof(int)*n);
	for (i = 1; i <= n; i++){
		scanf("%d", &A[i]);
		if (max<A[i]){ max = A[i]; }
	}

	Counting_Sort(A, B, max, n);

	for (i = 1; i <= n; i++){
		printf("%d", B[i]);
		if (i < n){
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}
