#include <stdio.h>

#define Max 100

void  swap(int *x, int *y)
{
    int  buff;
	
	buff = *x;
	*x = *y;  
	*y = buff;
}

int selectionSort(int A[Max], int N) {
	int i, j, minj;
	int count = 0;

	for (i = 0; i < N; i++) {
		minj = i;
		for (j = i; j < N; j++) {
			if (A[j] < A[minj])
				minj = j;
		}
		if (i != minj) {
			swap(&A[i], &A[minj]);
			count++;
		}
	}

	return count;
}

int main( ) {
	int N, i, count;
	int num[Max];

	scanf("%d", &N);

	for (i = 0; i < N; i++) scanf("%d", &num[i]);

	count = selectionSort(num, N);

	for (i = 0; i < N - 1; i++)
		printf("%d ", num[i]);
	printf("%d\n", num[N - 1]);

	printf("%d\n", count);

	return 0;
}
