#include <stdio.h>
#define N 100

int selectionSort(int A[N],int n){
	
	int swap = 0,temp,min;
	for( int i = 0; i < n; i++){
		min = i;
		for( int j = i; j < n; j++){
			if( A[j] < A[min] ) min = j;
		}
		if( min != i ){
			temp = A[i];
			A[i] = A[min];
			A[min] = temp;
			swap++;
		}
	}
	
	return swap;
	
}

int main(void){
	
	int A[N];
	int n,swap;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}
	
	swap = selectionSort(A,n);
	
	for(int i = 0; i < n; i++){
		if( i == n-1 ){
			printf("%d\n", A[i]);
			break;
		}
		printf("%d ", A[i]);
	}
	printf("%d\n", swap);
	
}
