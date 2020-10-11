/* ALDS1_2_B: Selection Sort */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 100

int selectionSrot(int *A, int n);
void swap(int *A, int x, int y);

int main(void){
	int i = 0, j, n, A[N] = {0}, sw;

	scanf("%d", &n);
	while(i < n) scanf("%d", &A[i++]); 
	
	sw = selectionSrot(A, n);

	printf("%d", A[0]);
	for(i = 1; i < n; i++){
		printf(" %d", A[i]);
	}

	printf("\n%d\n", sw);

	return 0;
}

int selectionSrot(int *A, int n){
	int min_id, i, j, sw = 0;

	for(i = 0; i < n - 1; i++){
		min_id = i;
		for(j = i+1; j < n; j++){
			if(A[j] < A[min_id]){
				min_id = j;
			}
		}

		if(min_id != i){
			swap(A, i, min_id);
			sw++;
		}
	}

	return sw;
}

void swap(int *A, int x, int y){
	int temp;
	 
	temp = A[x];
	A[x] =  A[y];
	A[y] = temp;
}
