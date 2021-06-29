#include <stdio.h>

void youso(int A[], int N)
{
	int i;

	for(i = 0; i < N; i++){
		if(i > 0){printf(" ");}
			printf("%d", A[i]);
	}
	printf("\n");
}

void insertionSort(int A[], int N)
{
	int i, j, v;

	for(i = 1; i < N; i++){
		v = A[i];
		j = i-1;
		while(j >= 0 && A[j] > v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		youso(A, N);
	}
}


int main(void)
{

	int i, N, A[1000];

	scanf("%d", &N);

	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}

	youso(A, N);
	insertionSort(A, N);

	return 0;
}

