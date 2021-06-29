#include<stdio.h>

int selectionSort(int A[], int N)
{
	int i, j, t, sw = 0, minj;

	for ( i = 0; i < N - 1; i++)
	{
		minj = i; //とりあえず最小の位置を先頭に仮置き
		for (j = i; j < N; j++)
		{
			if( A[j] < A[minj] ) minj = j; // minjを変えていき
		}
		t = A[i]; A[i] = A[minj]; A[minj] = t; // 一時変数tを使って入れ替え
		if( i != minj ) sw++;
	}
	return sw;
}

int main()
{
	int A[100], N, i, sw;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	sw = selectionSort(A, N);
	for (i = 0; i < N; i++)
	{
		if( i > 0 ) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
	printf("%d\n", sw);
	return 0;
}
