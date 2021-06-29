#include <stdio.h>

void printOneLine(int A[], int N)
{
	int i;
	
	for(i = 0; i < N; i++){
		if(i != 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}

void insertionSort(int A[], int N)
{
	int i, j, v;
	
	printOneLine(A, N);
	for(i = 1; i <= N-1; i++){
		v = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		printOneLine(A, N);
	}
}

int main(void)
{
	int N, A[100];
	int i, v;
	
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	
	insertionSort(A, N);
	
	return(0);
}

