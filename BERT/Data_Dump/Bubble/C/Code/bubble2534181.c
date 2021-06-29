#include<stdio.h>
#define MAX 100

void inputData(int *R, int *N)
{
	scanf("%d", N);
	for (int i = 0; i < *N; i++)
	{
		scanf("%d", &R[i]);
	}
}

void traceData(int *R, int N)
{
	int i;
	for (i = 0; i < (N - 1); i++)
	{
		printf("%d ", R[i]);
	}
	printf("%d\n", R[i]);
}

int bubbleSort(int *R, int N)
{
	int swappingCount = 0;

	for(int i=0; i<(N-1); i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (R[j - 1] > R[j])
			{
				int temp = R[j];
				R[j] = R[j - 1];
				R[j - 1] = temp;
				swappingCount++;
			}
		}
	}
	return swappingCount;
}

int main(void)
{
	int R[MAX], N;
	inputData(R, &N);
	int t = bubbleSort(R, N);
	traceData(R, N);
	printf("%d\n", t);
	return 0;
}
