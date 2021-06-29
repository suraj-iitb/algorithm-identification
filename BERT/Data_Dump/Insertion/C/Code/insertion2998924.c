#include <stdio.h>

int insertSort( int * Arr, int No );

int main(void)
{
	int No = 0;
	int Arr[100] = {};
	int i = 0;
	
	scanf( "%d", &No );
	
	for ( i = 0; i < No; i++ ) {
		scanf( "%d ", &Arr[i] );
	}
	
	insertionSort( Arr, No );
	
	return 0;
}

int insertionSort( int * Arr, int No ) {
	int i = 0;
	int j = 0;
	int v = 0;
	
	for ( i = 1; i < No; i++ ) {
		for ( j = 0; j < No-1; j++ ) {
			printf("%d ", Arr[j]);
		}
		printf("%d\n", Arr[j]);
		v = Arr[i];
		j = i-1;
		while ( j >= 0 && Arr[j] > v ) {
			Arr[j+1] = Arr[j];
			j--;
		}
		Arr[j+1] = v;
	}
	for ( j = 0; j < No-1; j++ ) {
		printf("%d ", Arr[j]);
	}
	printf("%d\n", Arr[j]);
	return 0;
}

