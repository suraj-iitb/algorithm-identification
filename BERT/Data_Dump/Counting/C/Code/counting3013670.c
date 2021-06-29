#include <stdio.h>
#include <stdlib.h>

#define N 2500000

void CountingSort(int *A, int *B, int k, int n );



int main(void)
{
	int max_order	= 0;
	int Arr[N]		= {};
	int Out[N]		= {};
	char str[4*N]	= {};
	int i			= 0;
	int maximum		= 0;
	
	fgets(str, 4*N, stdin);
	max_order = atoi(str);
	
	scanf( "%d*", &Arr[0] );
	maximum = Arr[0];
	for ( i = 1; i < max_order; i++ ) {
		scanf( "%d*", &Arr[i] );
		if ( maximum < Arr[i] ) {
			maximum = Arr[i];
		}
	}
	
	
	
	CountingSort(Arr, Out, maximum+1, max_order );
	
	for ( i = 0; i < max_order - 1; i++ ) {
		printf( "%d ", Out[i]);
	}
	
	printf("%d\n", Out[i]);
	
	return 0;
}

void CountingSort(int *A, int *B, int k, int n )
{
	int C[10001] = {};
	int i = 0;
	
	for ( i = 0; i < k; i++ ) {
		C[i] = 0;
	}
	
	for ( i = 0; i < n; i++ ) {
		C[A[i]]++;
	}

	for ( i = 1; i < k; i++ ) {
		C[i] = C[i] + C[i-1];
	}
	
	for ( i = n-1; i >=0 ; i-- ) {
		B[C[A[i]]-1] = A[i];
		C[A[i]]--;
	}
	
	return;
}
	

