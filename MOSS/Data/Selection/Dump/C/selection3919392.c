#include<stdio.h>

int selectionSort(int *a, int N)
{
	int swap = 0;
	for (int i = 0; i < N; i++)
	{
		int min = i;
		for (int j = i + 1; j < N; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		if (min != i)
		{
			int t = a[min];
			a[min] = a[i];
			a[i] = t;
			swap++;
		}
	}
	return swap;
}

void print(int *a, int N)
{
	for (int i = 0; i < N; i++)
	{
		if (i)
			printf(" ");
		printf("%d", a[i]);
	}
}

int main()
{
	int N;
	int a[101];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	int sw = selectionSort(a, N);
	print(a, N);
	printf("\n%d\n", sw);
}
