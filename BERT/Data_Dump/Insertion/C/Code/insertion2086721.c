#include<stdio.h>

void insertionSort(int A[], int N){
	int i = 0, j = 0;
	int v = 0;
	printf("%d", A[0]);
	for( j = 1; j < N; j++ ){
		printf(" %d", A[j]);
	}
	printf("\n");
	for( i = 1; i < N; i++ ){
		v = A[i];
		for( j = i-1; j >= 0 && A[j] > v; j-- ){
			A[j+1] = A[j];
		}
		A[j+1] = v;
		printf("%d", A[0]);
		for( j = 1; j < N; j++ ){
			printf(" %d", A[j]);
		}
		printf("\n");
	}
}


int main(){
	int N = 0;;
	int A[1000];
	int i = 0;
	scanf("%d", &N);
	for( i = 0; i < N; i++ ){ scanf("%d", &A[i]); }
	insertionSort(A, N);
	return 0;
}
