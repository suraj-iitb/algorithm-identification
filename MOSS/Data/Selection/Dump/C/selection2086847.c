#include<stdio.h>

int selectionSort(int A[], int N){
	int temp = 0;
	int i = 0, j = 0;
	int minj = 0;
	int times = 0;
	for( i = 0; i < N; i++ ){
		minj = i;
		for( j = i; j < N; j++ ){
			if( A[minj] > A[j] ){
				minj = j;
			}
		}
		if( minj != i ){
			temp = A[i];
			A[i] = A[minj];
			A[minj] = temp;
			times++;
		}
	}
	return times;
}

int main(){
	int N = 0;;
	int A[100];
	int i = 0;
	int re = 0;
	scanf("%d", &N);
	for( i = 0; i < N; i++ ){ scanf("%d", &A[i]); }
	re = selectionSort(A, N);
	printf("%d", A[0]);
	for( i = 1; i < N; i++ ){
		printf(" %d", A[i]);
	}
	printf("\n");
	printf("%d\n", re);
	return 0;
}
