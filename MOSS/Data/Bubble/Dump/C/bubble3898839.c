#include <stdio.h>
#define N 100

int bubbleSort(int A[N],int n){
	
	int swap = 0,temp;
	for(int i = 0; i < n-1; i++){
		for(int j = n-1; j > i; j--){
			if( A[j] < A[j-1]){
				temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;
				swap++;
			}
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
	
	swap = bubbleSort(A,n);
	
	for(int i = 0; i < n; i++){
		if( i == n-1 ){
			printf("%d\n", A[i]);
			break;
		}
		printf("%d ", A[i]);
	}
	printf("%d\n", swap);
	
}
