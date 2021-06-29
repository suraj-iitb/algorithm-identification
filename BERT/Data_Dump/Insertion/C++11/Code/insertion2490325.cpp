#define		_CRT_SECURE_NO_WARNINGS

#include	<cstdio>

int main()
{
	int		N;
	int		A[1000];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &(A[i]));
	}

	for (int i = 1; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			if (k) printf(" ");
			printf("%d", A[k]);
		}
		printf("\n");

		int	v = A[i];
		int j = i - 1;

		while ((j >= 0) && (A[j] > v))
		{
			A[j + 1] = A[j];
			j--;
		}

		A[j + 1] = v;
	}

	for (int k = 0; k < N; k++)
	{
		if (k) printf(" ");
		printf("%d", A[k]);
	}
	printf("\n");

	return 0;
}
