#include <stdio.h>

void printOneLine(int A[], int N, int cnt)
{
	int i;
	
	for(i = 0; i < N; i++){
		if(i != 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n%d\n", cnt);
}

void selectionSort(int A[], int N)
{
	int i, j, minj, cnt = 0;
	
	for(i = 0; i < N; i++){
		minj = i;
		for(j = i; j < N; j++){
			if(A[j] < A[minj]){
				minj = j;
			}
		}
		if(minj != i){
			A[i]    ^= A[minj];
			A[minj] ^= A[i];
			A[i]    ^= A[minj];
			cnt++;
		}
	}
	printOneLine(A, N, cnt);
}

int main(void)
{
	int i, N, A[100];
	
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	
	selectionSort(A, N);
	
	return(0);
}

