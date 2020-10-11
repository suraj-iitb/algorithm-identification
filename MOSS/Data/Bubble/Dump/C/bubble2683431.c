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

void bubbleSort(int A[], int N)
{
	int i, j, cnt = 0;
	
	for(i = 0; i < N-1; i++){
		for(j = N-1; j >= i+1; j--){
			if(A[j] < A[j-1]){
				A[j]   ^= A[j-1];
				A[j-1] ^= A[j];
				A[j]   ^= A[j-1];
				cnt++;
			}
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
	
	bubbleSort(A, N);
	
	return(0);
}

