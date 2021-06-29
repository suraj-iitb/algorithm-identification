#include <stdio.h>

void printOut(int A[100], int N){
	
	for(int i = 0; i < N; i++){
		printf("%d", A[i]);
		if( i != N-1 ) printf(" ");
	}
	
}

int main(void){
	
	int N,key;
	int A[100];
	int i,j,k;
	
	scanf("%d", &N);
	
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	
	for(i = 1; i < N; i++){
		printOut(A, N);
		printf("\n");
		key = A[i];
		j = i-1;
		while( j >= 0 && A[j] > key){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
	printOut(A, N);
	printf("\n");
	
}
