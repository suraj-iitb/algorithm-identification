#include <stdio.h>

void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
int selectionsort(int a[], int N, int count)
{
	int mini;
	for (int i = 0; i < N; i++)
	{
		mini = i;
		for (int j = i; j < N; j++)
		{
			if (a[j] < a[mini])
			{
				mini = j;
			}
		}
		if (a[i] != a[mini])
		{
			swap(&a[i], &a[mini]);
			++count;
		}
		
	}
	return count;
}

void print(int a[], int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d", a[i]);
		if (i != N - 1)
		{
			printf(" ");
		}
	}
	printf("\n");
}
int main()
{
	int count = 0;
	int a[100];
	int N;
	scanf("%d", &N);


	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}



	count = selectionsort(a, N, count);
	print(a, N);
	printf("%d\n", count);


	return 0;
}
