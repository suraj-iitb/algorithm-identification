/*
 *	Argorithms and Data Structures
 *	Lectuire 2
 *	Selecton Sort
 */

#include <stdio.h>

#define MAX_N 100

int main(void){
	int A[MAX_N], N;
	int i, j, minj, hoge, count = 0;

	scanf("%d", &N);
	for(i=0; i<N; i++)
		scanf("%d", &A[i]);

	for( i=0; i<N; i++){
		minj = i;
		for( j = i+1; j<N; j++){
			if( A[j] < A[minj])
				minj = j;
		}
		if( minj != i){
			hoge = A[i];
			A[i] = A[minj];
			A[minj] = hoge;
			count++;
		}
	}

	for( i=0; i<N-1; i++)
		printf("%d ", A[i]);
	printf("%d\n%d\n", A[i], count);

	return 0;
}	
