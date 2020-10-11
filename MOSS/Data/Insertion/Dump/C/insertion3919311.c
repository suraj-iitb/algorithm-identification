#include<stdio.h>

void print(int *a, int N)
{
	for (int i = 0; i < N; i++)
	{
		if (i)
			printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
}

void insertionSort(int *a, int N)
{
	int i, j, v;
	for (i = 1; i < N; i++)
	{
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		print(a, N);
	}
}

int main()
{
	int N;
	int a[101];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	print(a, N);
	insertionSort(a, N);
}
