/*ALDS1_2_A:Bubble Sort*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 100

int bubbleSort(int *A, int n);
void swap(int *A, int x, int y);

int main(void){
	int n, i = 0, A[N] = {0}, sw;

	scanf("%d", &n);
	while(i < n) scanf("%d", &A[i++]);

	sw = bubbleSort(A, n);

	for( i = 0; i < n; i++){
		if(i > 0) printf(" ");
		printf("%d", A[i]);
	}

	printf("\n%d\n", sw);

	return 0;
}

int bubbleSort(int *A, int n){
	int sw = 0, i, j;

	for(i = 0; i < n-1; i++){
		for(j = n-1; j > i; j--){
			if(A[j] < A[j - 1]){
				swap(A, j, j-1);
				sw++;
			}
		}
	}

	return sw;
}

void swap(int *A, int x, int y){
	int temp;

	temp = A[x];
	A[x] = A[y];
	A[y] = temp;
}
