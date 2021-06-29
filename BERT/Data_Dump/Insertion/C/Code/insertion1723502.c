/*
 *	Argorithms and Data Structures
 *	Lectuire 1
 *	Insertion Sort
 */

#include <stdio.h>

#define ARRAYMAX 1000

void display_array(int*, int);

int main(void){
	int i, j, v, N, A[ARRAYMAX];
	
	scanf("%d",&N);
	for( i=0; i<N; i++) scanf("%d", &A[i]);

	display_array(A, N);

	for( i=1; i<N; i++){
		v = A[i];
		j = i-1;
		while( j>=0 && A[j] > v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;

		display_array(A, N);
	}
	return 0;
}

void display_array(int A[], int N){
	int i;
	for( i=0; i<N-1; i++)
		printf("%d ", A[i]);
	printf("%d\n", A[i]);
}
