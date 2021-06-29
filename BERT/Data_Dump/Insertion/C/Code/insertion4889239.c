#include<stdio.h>


void insertionSort(int A[], int N) {
	
	int i, j, k, v;
	
	
	
	for(i = 1; i < N; i++) {
		
		for(k = 0; k < N; k++) {
			if(k <= N-2) printf("%d ", A[k]);
			else printf("%d", A[k]);
		}
		printf("\n");
		
		v = A[i];
		j = i - 1;
		
		while(j >= 0 && A[j] > v) {
			
			A[j+1] = A[j];
			j--;
			
		}
		
		A[j+1] = v;
		
	}
}


int main(void) {
	
	int i, N;
	int A[100];
	
	scanf("%d", &N);
	
	for(i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	
	insertionSort(A, N);
	
	for(i = 0; i < N; i++) {
			if(i <= N-2) printf("%d ", A[i]);
			else printf("%d", A[i]);
		}
		printf("\n");
}

