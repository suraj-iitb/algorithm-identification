/*
 *	Argorithms and Data Structures
 *	Lectuire 2
 *	Bubble Sort
 */

#include <stdio.h>

#define MAX_N 100

int main(void){
	int A[MAX_N], N;
	int i, j, count = 0, hoge;

	scanf("%d", &N);
	for( i=0; i<N; i++)
		scanf("%d", &A[i]);


	for( i=0; i<N-1; i++){
		for( j=N-1; j>i; j--){
			 if( A[j] < A[j-1]){
				 hoge = A[j];
				 A[j] = A[j-1];
				 A[j-1] = hoge;
				 count++;
			 }
		}
	}

	for( i=0; i<N-1; i++)
		printf("%d ", A[i]);
	printf("%d\n", A[i]);
	printf("%d\n", count);

	return 0;
}
