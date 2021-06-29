#include <stdio.h>

void	printArray(int *A, int N)
{
	int	i;

	i = 0;
	while(i < N)
	{
		if (i == N - 1)
			printf("%d", A[i]);
		else
			printf("%d ", A[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	int	N;
	int	A[1001];
	int	v;
	int	j;

	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &A[i]);
	printArray(A, N);
	for(int i=1; i<N; i++)
	{
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		printArray(A, N);
	}
	return (0);
}


