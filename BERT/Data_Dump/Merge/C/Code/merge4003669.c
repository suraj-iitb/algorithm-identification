#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10000000

int cnt;
void Merge( int[], int, int, int );
void MergeSort( int[], int, int );

int main( void ){
	int i, L;
	int a[N];
	
	cnt = 0;
	
	scanf("%d", &L );
	for( i = 0; i < L; i++ ){
		scanf("%d", &a[i] );
	}
	
	MergeSort( a, 0, L );
	
	for( i = 0; i < L; i++ ){
		printf("%d", a[i] );
		if( i < L-1 ){
			printf(" ");
		}
	}
	printf("\n");
	printf("%d\n", cnt );
	
	return 0;
}

void Merge( int a[], int left, int mid, int right ){
	int i, j, k;
	int n_1 = mid-left;
	int n_2 = right-mid;
	
	int L[n_1+1], R[n_2+1];
	
	for( i = 0; i < n_1; i++ ){
		L[i] = a[left+i];
	}
	for( i = 0; i < n_2; i++ ){
		R[i] = a[mid+i];
	}
	
	L[n_1] = (int)INFINITY;
	R[n_2] = (int)INFINITY;
	
	i = 0; j = 0;
	for( k = left; k < right; k++ ){
		cnt++;
		if( L[i] <= R[j] ){
			a[k] = L[i];
			i++;
		}
		else{
			a[k] = R[j];
			j++;
		}
	}
}

void MergeSort( int a[], int left, int right ){
	int mid;
	if( left+1 < right ){
		mid = (left+right)/2;
		MergeSort( a, left, mid );
		MergeSort( a, mid, right );
		Merge( a, left, mid, right );
	}
}
