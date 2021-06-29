#include <stdio.h>

#define Max 1000

void  swap(int *x, int *y)
{
    int  buff;
	
	buff = *x;
	*x = *y;  
	*y = buff;
}

int bubbleSort(int A[Max], int N) {
	int i, j;
	int flag = 1;
	int count = 0;

	while (flag) {
		flag = 0;
		for (j = N - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				swap(&A[j], &A[j - 1]);
				flag = 1;
				count++;
			}
		}
	}

	return count;
}

int main( ) {
	int N, i, count;
	int num[Max];

	scanf("%d", &N);

	for (i = 0; i < N; i++) scanf("%d", &num[i]);

	count = bubbleSort(num, N);

	for (i = 0; i < N - 1; i++)
		printf("%d ", num[i]);
	printf("%d\n", num[N - 1]);

	printf("%d\n", count);

	return 0;
}
