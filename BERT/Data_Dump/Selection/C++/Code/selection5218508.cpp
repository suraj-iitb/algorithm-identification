#include<iostream>
#include<stdio.h>
using namespace std;

int selectionSort(int A[], int N) {
	int count = 0;
	int i, j, t;
	for (i = 0; i < N-1; i++) {
		int minj = i;
		for(j=i;j<N;j++){
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
	
		swap(A[i], A[minj]);
		if (i != minj) {
			count++;
		}
	}
	return count;
}

int main() {
	int A[100], N, i, count;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d",&A[i]);
		
	}
	count = selectionSort(A, N);
	for (i = 0; i < N; i++) {
		if (i > 0)printf(" ");
		printf("%d", A[i]);
		
		
	}
	printf("\n");
	printf("%d\n", count);
	return 0;
}
