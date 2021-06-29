#include<stdio.h>

int main(){
	int A[101], N, i, swap, count, j, l;

	scanf("%i", &N);

	
	for (l= 0; l<N; l++)
	{
		scanf("%d", &A[l]);
	}

	
	
	for (i = 0; i < N; i++)
	{
		for (j = N-1; j >= i + 1; j--)
		{
			if (A[j] < A[j-1])
			{
				swap = A[j];
				A[j] = A[j-1];
				A[j-1] = swap;
				count++;
			}
		}
	}

	int k;
	for (k = 0; k < N-1; k++)
	{
		printf("%d ", A[k]);
	}
	printf("%d", A[N-1]);
	printf("\n");
	printf("%i\n", count);

	return 0;
	
}


