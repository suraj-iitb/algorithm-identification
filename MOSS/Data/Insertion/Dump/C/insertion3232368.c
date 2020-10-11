#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 100
void trace(int *A, int n);
void insertionSort(int *A, int n);

int main(void){
	int n, i = 0, A[N] = {0};

	scanf("%d", &n);
	while(i < n) scanf("%d", &A[i++]);

	trace(A, n);
	insertionSort(A, n);

	return 0;
}

void trace(int *A, int n){
	int i = 0;

	while(i < n){
		if(i > 0) printf(" ");
		printf("%d", A[i++]);
	}

	putchar('\n');
}

void insertionSort(int *A, int n){
	int v, i, j;

	for(i = 1; i < n; i++){
		v = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > v){
			A[j + 1] = A[j];
			j--;
		} 
		A[j + 1] = v;
		trace(A, n);
	}
}
